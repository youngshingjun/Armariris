//===- LanaiRegisterInfo.h - Lanai Register Information Impl ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Lanai implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_LANAI_LANAIREGISTERINFO_H
#define LLVM_LIB_TARGET_LANAI_LANAIREGISTERINFO_H

#include "llvm/Target/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "LanaiGenRegisterInfo.inc"

namespace llvm {

class TargetInstrInfo;
class Type;

struct LanaiRegisterInfo : public LanaiGenRegisterInfo {
  LanaiRegisterInfo();

  const uint32_t *getCallPreservedMask(const MachineFunction &MF,
                                       CallingConv::ID) const override;

  // Code Generation virtual methods.
  const uint16_t *
  getCalleeSavedRegs(const MachineFunction *MF = 0) const override;

  BitVector getReservedRegs(const MachineFunction &MF) const override;

  bool requiresRegisterScavenging(const MachineFunction &MF) const override;

  bool trackLivenessAfterRegAlloc(const MachineFunction &MF) const override;

  void eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = NULL) const override;

  bool canRealignStack(const MachineFunction &MF) const override;

  // Debug information queries.
  unsigned getRARegister() const;
  unsigned getFrameRegister(const MachineFunction &MF) const override;
  unsigned getBaseRegister() const;
  bool hasBasePointer(const MachineFunction &MF) const;

  // Exception handling queries.
  unsigned getEHExceptionRegister() const;
  unsigned getEHHandlerRegister() const;
  int getDwarfRegNum(unsigned RegNum, bool IsEH) const;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_LANAI_LANAIREGISTERINFO_H
