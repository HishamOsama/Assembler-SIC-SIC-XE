#include "InstructionHandlerFactory.h"
#include "DirectiveInstructionHandler.h"
#include "MemoryInstructionHandler.h"
#include "SimpleDirectiveInstructionHandler.h"
#include "InstructionHandlerConstants.h"
#include "NonExistingInstructionHandler.h"

using namespace std;

InstructionHandlerFactory::InstructionHandlerFactory()
{

}

InstructionHandlerFactory*
    InstructionHandlerFactory::instructionHandlerFactoryInstance = new InstructionHandlerFactory();

InstructionHandlerFactory* InstructionHandlerFactory::getInstance() {
    return InstructionHandlerFactory::instructionHandlerFactoryInstance;
}

InstructionHandler* InstructionHandlerFactory::getInstructionHandler
    (string type, string instruction, string operand) {
    InstructionHandler* ptr;
    if (type == InstructionHandlerConstants::INSTRUCTION_TYPE_DIR) {
        ptr = new DirectiveInstructionHandler(instruction, operand);
    } else if (type == InstructionHandlerConstants::INSTRUCTION_TYPE_MEMREG) {
        ptr = new MemoryInstructionHandler(operand);
    } else if (type == InstructionHandlerConstants::INSTRUCTION_TYPE_OPER) {
        ptr = new SimpleDirectiveInstructionHandler(instruction);
    } else {
        ptr = new NonExistingInstructionHandler();
    }
    return ptr;
}
