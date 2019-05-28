///////////////////////////////////////////////////////////////////////
///
/// \file   IGenNoise.h
///
/// \brief  This is the interface class for a tool to handle a GenNoise
///         for the overall response
///
/// \author T. Usher
///
////////////////////////////////////////////////////////////////////////

#ifndef IGenNoise_H
#define IGenNoise_H

#include "fhiclcpp/ParameterSet.h"
#include "CLHEP/Random/RandomEngine.h"

class TComplex;

namespace icarus_tool
{
    class IGenNoise
    {
    public:
        virtual ~IGenNoise() noexcept = default;
        
        virtual void configure(const fhicl::ParameterSet& pset)                   = 0;
        
        virtual void nextEvent()                                                  = 0;
        
        virtual void generateNoise(CLHEP::HepRandomEngine& noise_engine,
                                   CLHEP::HepRandomEngine& cornoise_engine,
                                   std::vector<float>&, double, unsigned int = 0) = 0;
    };
}

#endif