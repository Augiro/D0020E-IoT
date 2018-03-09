/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: sysx2nrMessageDeconstruct
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2018-03-05/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#include "sysx2nrMessageDeconstruct.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "sysx2nrMessageDeconstruct_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_sysx2nrMessageDeconstruct, g_nStringIdsysx2nrMessageDeconstruct)

const CStringDictionary::TStringId FORTE_sysx2nrMessageDeconstruct::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdsysxJob};

const CStringDictionary::TStringId FORTE_sysx2nrMessageDeconstruct::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_sysx2nrMessageDeconstruct::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdbatchSize, g_nStringIdbatchCounter, g_nStringIdtorque, g_nStringIdtorqueMax, g_nStringIdtorqueMin, g_nStringIdtorqueFinalTarget, g_nStringIdangle, g_nStringIdangleMax, g_nStringIdangleMin, g_nStringIdangleFinalTarget};

const CStringDictionary::TStringId FORTE_sysx2nrMessageDeconstruct::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING};

const TForteInt16 FORTE_sysx2nrMessageDeconstruct::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_sysx2nrMessageDeconstruct::scm_anEIWith[] = {0, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_sysx2nrMessageDeconstruct::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_sysx2nrMessageDeconstruct::scm_anEOWith[] = {0, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 255};
const TForteInt16 FORTE_sysx2nrMessageDeconstruct::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_sysx2nrMessageDeconstruct::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_sysx2nrMessageDeconstruct::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  11,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_sysx2nrMessageDeconstruct::alg_initialize(void){

QO() = QI();
}

void FORTE_sysx2nrMessageDeconstruct::alg_deInitialize(void){

QO() = false;
}

void FORTE_sysx2nrMessageDeconstruct::alg_normalOperation(void){
QO() = QI();

if((true == QI())){
/*   only perform normal operation of QI is true*/

};

}


void FORTE_sysx2nrMessageDeconstruct::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_sysx2nrMessageDeconstruct::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  alg_initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_sysx2nrMessageDeconstruct::enterStateNormalOp(void){
  m_nECCState = scm_nStateNormalOp;
  alg_normalOperation();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_sysx2nrMessageDeconstruct::enterStateInitialized(void){
  m_nECCState = scm_nStateInitialized;
}

void FORTE_sysx2nrMessageDeconstruct::enterStateDeInit(void){
  m_nECCState = scm_nStateDeInit;
  alg_deInitialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_sysx2nrMessageDeconstruct::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if((scm_nEventINITID == pa_nEIID) && ((true == QI())))
          enterStateInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNormalOp:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialized:
        if(scm_nEventREQID == pa_nEIID)
          enterStateNormalOp();
        else
        if((scm_nEventINITID == pa_nEIID) && ((false == QI())))
          enterStateDeInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDeInit:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


