/**\class Definitions Definitions.cc MssmHbbAnalysis/Ntuplizer/src/Definitions.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Roberval Walsh Bastos Rangel
//         Created:  Mon, 20 Oct 2014 14:24:08 GMT
//
//

// system include files
// 
// user include files
#include "FWCore/Framework/interface/Event.h"
// 
#include "FWCore/ParameterSet/interface/ParameterSet.h"
 
#include "MssmHbbAnalysis/Ntuplizer/interface/Definitions.h"


//
// class declaration
//

using namespace mssmhbb;
using namespace mssmhbb::ntuple;

//
// constructors and destructor
//
Definitions::Definitions()
{
   // default constructor
}

Definitions::Definitions(edm::Service<TFileService> & fs)
{
   std::string name = "Definitions";
   tree_ = fs->make<TTree>(name.c_str(),name.c_str());
   
}

Definitions::~Definitions()
{
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)
}


//
// member functions
//

// ------------ method called for each event  ------------
void Definitions::Fill()
{
   tree_ -> Fill();
}

// ------------ method called once each job just before starting event loop  ------------
void Definitions::Init()
{
}

void Definitions::Add(const std::vector<std::string> & names, const std::vector<std::string> & aliases)
{
   for ( size_t i = 0 ; i < names.size() ; ++i )
      this -> Add(names[i],aliases[i]);
}

void Definitions::Add(const std::string & name, const std::string & alias)
{
   tree_ ->Branch(alias.c_str(),(void*)name.c_str(),"string/C",1024);
}

// ------------ other methods ----------------
TTree * Definitions::Tree()
{
   return tree_;
}

