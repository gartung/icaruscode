#ifndef SPACECHARGESERVICEICARUS_H
#define SPACECHARGESERVICEICARUS_H

#include "fhiclcpp/ParameterSet.h"
#include "art/Framework/Services/Registry/ActivityRegistry.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Services/Registry/ServiceDeclarationMacros.h"
#include "art/Framework/Principal/Run.h"
#include "icaruscode/TPC/Simulation/SpaceCharge/SpaceChargeICARUS.h"
#include "larevt/SpaceChargeServices/SpaceChargeService.h"


namespace spacecharge
{
  class SpaceChargeServiceICARUS : public SpaceChargeService
  {
  public:
    SpaceChargeServiceICARUS(fhicl::ParameterSet const& pset, art::ActivityRegistry& reg\
			   );

    void   reconfigure(fhicl::ParameterSet const& pset);
    void   preBeginRun(const art::Run& run);


    virtual const  provider_type* provider() const override
    {
      return fProp.get();
    }

  private:

    std::unique_ptr<spacecharge::SpaceChargeICARUS> fProp;

  }; // class SpaceChargeServiceICARUS                                                     
} //namespace spacecharge                                                                  
DECLARE_ART_SERVICE_INTERFACE_IMPL(spacecharge::SpaceChargeServiceICARUS, spacecharge::SpaceChargeService, LEGACY)
#endif // SPACECHARGESERVICEICARUS_H     
