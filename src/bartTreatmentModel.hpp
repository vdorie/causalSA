#ifndef CIBART_BART_TREATMENT_MODEL_HPP
#define CIBART_BART_TREATMENT_MODEL_HPP

#include "treatmentModel.hpp"

#include <cstddef> // size_t

namespace cibart {
  struct BARTTreatmentModelFunctionTable;
  
  typedef void* (*voidPtrFunction)(void);
  typedef voidPtrFunction (*voidPtrFunctionLookup)(const char* _namespace, const char* name);
  
  struct BARTTreatmentModel : TreatmentModel {
    std::size_t numTrees;
    std::size_t numThin;
    
    double nodePriorParameter;
    
    BARTTreatmentModelFunctionTable* functionTable;
    
    BARTTreatmentModel(voidPtrFunctionLookup lookup, std::size_t numTrees, std::size_t numThin, double nodePriorParameter);
    ~BARTTreatmentModel();
  };
}

#endif // CIBART_BART_TREATMENT_MODEL_HPP
