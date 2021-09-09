/**
 * @file   DumpTriggerGateData_module.cc
 * @brief  Dumps on console the content of a
 *         `icarus::trigger::OpticalTriggerGate::GateData_t` data product.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   December 6, 2019
 */

// ICARUS libraries
#include "icaruscode/PMT/Trigger/Utilities/TriggerGateDataFormatting.h" // compactdump()
#include "sbnobj/ICARUS/PMT/Trigger/Data/OpticalTriggerGate.h"

// LArSoft libraries
#include "lardataobj/RawData/OpDetWaveform.h"
#include "larcorealg/CoreUtils/enumerate.h"

// framework libraries
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "canvas/Utilities/InputTag.h"
#include "canvas/Persistency/Common/Assns.h"
#include "messagefacility/MessageLogger/MessageLogger.h"
#include "fhiclcpp/types/Atom.h"

// C/C++ standard libraries
#include <vector>
#include <string>
#include <set>
#include <optional>
#include <type_traits> // std::decay_t


//------------------------------------------------------------------------------
namespace icarus::trigger { class DumpTriggerGateData; }

/**
 * @brief Produces plots to inform trigger design.
 * 
 * This module produces sets of plots based on the configured trigger settings.
 * 
 * 
 * Input data products
 * ====================
 * 
 * * `std::vector<raw::OpDetWaveform>`: a single waveform for each recorded
 *      optical detector activity; the activity belongs to a single channel, but
 *      there may be multiple waveforms on the same channel. The time stamp is
 *      expected to be from the
 *      @anchor DetectorClocksElectronicsTime "electronics time scale"
 *      and therefore expressed in microseconds.
 * * `std::vector<simb::MCTruth>`: generator information, used for categorising
 *      the events for plot sets
 * 
 * 
 * 
 * Output plots
 * =============
 * 
 * For each event category, a set of plots is left into a ROOT subdirectory.
 * 
 * @todo Document which plots these are!
 * 
 * 
 * 
 * Configuration parameters
 * =========================
 * 
 * A terse description of the parameters is printed by running
 * `lar --print-description DumpTriggerGateData`.
 * 
 * @todo Complete the documentation
 * 
 * * `TriggerGateDataTag` (data product input tag): the tag identifying the
 *     data product to dump; instance names are specified introduced by a colon:
 *     `"modulelabel:instance"`.
 * 
 * 
 * 
 */
class icarus::trigger::DumpTriggerGateData: public art::EDAnalyzer {
  
    public:
  
  /// The type of data this dumper is dumping.
  using TriggerGateData_t = icarus::trigger::OpticalTriggerGate::GateData_t;
  

  // --- BEGIN Configuration ---------------------------------------------------
  struct Config {
    
    using Name = fhicl::Name;
    using Comment = fhicl::Comment;
    
    fhicl::Atom<art::InputTag> TriggerGateDataTag {
      Name("TriggerGateDataTag"),
      Comment("tag of trigger gate data collection")
      };

    fhicl::Atom<bool> PrintChannels {
      Name("PrintChannels"),
      Comment("whether to print the channel of the gate"),
      true // default
      };

    fhicl::Atom<std::string> OutputCategory {
      Name("OutputCategory"),
      Comment("name of the category used for the output"),
      "DumpTriggerGateData"
      };

  }; // struct Config
  
  using Parameters = art::EDAnalyzer::Table<Config>;
  // --- END Configuration -----------------------------------------------------
  
  
  // --- BEGIN Constructors ----------------------------------------------------
  explicit DumpTriggerGateData(Parameters const& config);
  
  // Plugins should not be copied or assigned.
  DumpTriggerGateData(DumpTriggerGateData const&) = delete;
  DumpTriggerGateData(DumpTriggerGateData&&) = delete;
  DumpTriggerGateData& operator=(DumpTriggerGateData const&) = delete;
  DumpTriggerGateData& operator=(DumpTriggerGateData&&) = delete;
  
  // --- END Constructors ------------------------------------------------------
  
  
  // --- BEGIN Framework hooks -------------------------------------------------
  
  /// Fills the plots. Also extracts the information to fill them with.
  virtual void analyze(art::Event const& event) override;
  
  // --- END Framework hooks ---------------------------------------------------
  
  
    private:
  
  // --- BEGIN Configuration variables -----------------------------------------
  
  art::InputTag fTriggerGateDataTag; ///< Input trigger gate data tag.
  bool fPrintChannels; ///< Whether to print associated optical waveform info.

  std::string fOutputCategory; ///< Category used for message facility stream.
  
  // --- END Configuration variables -------------------------------------------
  
  
  // --- BEGIN Service variables -----------------------------------------------
  
//   detinfo::DetectorClocks const& fDetClocks;
//   detinfo::DetectorTimings fDetTimings;
//
//   /// Total number of optical channels (PMTs).
//   unsigned int fNOpDetChannels = 0;
//   microsecond const fOpDetTickDuration; ///< Optical detector sampling period.
  
  // --- END Service variables -------------------------------------------------
  
  
}; // icarus::trigger::DumpTriggerGateData


//------------------------------------------------------------------------------
//--- Implementation
//------------------------------------------------------------------------------
//--- icarus::trigger::DumpTriggerGateData
//------------------------------------------------------------------------------
icarus::trigger::DumpTriggerGateData::DumpTriggerGateData
  (Parameters const& config)
  : art::EDAnalyzer(config)
  // configuration
  , fTriggerGateDataTag(config().TriggerGateDataTag())
  , fPrintChannels     (config().PrintChannels())
  , fOutputCategory    (config().OutputCategory())
{
  consumes<std::vector<TriggerGateData_t>>(fTriggerGateDataTag);
  if (fPrintChannels) {
    consumes<art::Assns<TriggerGateData_t, raw::OpDetWaveform>>
      (fTriggerGateDataTag);
  }
  
} // icarus::trigger::DumpTriggerGateData::DumpTriggerGateData()


//------------------------------------------------------------------------------
void icarus::trigger::DumpTriggerGateData::analyze(art::Event const& event) {
  
  //
  // do the work
  //
  auto const& gates =
   *(event.getValidHandle<std::vector<TriggerGateData_t>>(fTriggerGateDataTag));
  auto const* gateToWaveforms = fPrintChannels
    ? event.getHandle<art::Assns<TriggerGateData_t, raw::OpDetWaveform>>
      (fTriggerGateDataTag).product()
    : nullptr
    ;
  
  auto maybeItOpDetWave { gateToWaveforms
    ? std::make_optional(gateToWaveforms->begin()): std::nullopt
    };

  mf::LogVerbatim log(fOutputCategory);
  log << event.id() << ": '" << fTriggerGateDataTag.encode() << "' has "
    << gates.size() << " trigger gates:";
  for (auto const& [ iGate, gate ]: util::enumerate(gates)) {
    log << "\n[#" << iGate << "] " << compactdump(gate);
    if (gateToWaveforms) {
      auto& itOpDetWave = maybeItOpDetWave.value();
      auto const owend = gateToWaveforms->end();

      /*
       * Associations are expected to be in the same order as the trigger gates;
       * so we look for the first one matching this gate
       * (matching by the position in the data product collection)
       * and then for the last one; if there is none... well, we say so.
       */
      while (itOpDetWave != owend) {
        if (itOpDetWave->first.key() == iGate) break;
        ++itOpDetWave;
      } // while
      if (itOpDetWave == owend) {
        log << "\n  (not associated with any optical detector waveform!)";
        continue;
      }
      auto const firstOpDetWave = itOpDetWave;
      std::set<raw::Channel_t> channels;
      while (itOpDetWave != owend) {
        if (itOpDetWave->first.key() != iGate) break;
        channels.insert(itOpDetWave->second->ChannelNumber());
        ++itOpDetWave;
      } // while

      log << "\n  associated with "
        << std::distance(firstOpDetWave, itOpDetWave)
        << " optical detector waveforms on ";
      if (channels.size() == 1U) {
        log << "channel " << *(channels.cbegin());
      }
      else {
        log << channels.size() << " channels:";
        for (auto const& channel: channels) log << " " << channel;
      }

    } // if printing associated information
  } // for

} // icarus::trigger::DumpTriggerGateData::analyze()


//------------------------------------------------------------------------------
DEFINE_ART_MODULE(icarus::trigger::DumpTriggerGateData)


//------------------------------------------------------------------------------
