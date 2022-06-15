#ifndef __INS
#define __INS

// by name
void LDA(uint8_t op);
void LDX(uint8_t op);
void LDY(uint8_t op);
void STA(uint16_t op);
void STX(uint16_t op);
void STY(uint16_t op);
void TAX();
void TAY();
void TSX();
void TXA();
void TXS();
void TYA();
void PHA();
void PHP();
void PLA();
void PLP();
void DEC(uint16_t op);
void DEX();
void DEY();
void INC(uint16_t op);
void INX();
void INY();
void ADC(uint8_t op);
void SBC(uint8_t op);
void AND(uint8_t op);
void EOR(uint8_t op);
void ORA(uint8_t op);
void ASL(uint8_t op);
void LSR(uint8_t op);
void ROL(uint8_t op);
void ROR(uint8_t op);
void CLC();
void CLD();
void CLI();
void CLV();
void SEC();
void SED();
void SEI();
void CMP(uint8_t op);
void CPX(uint8_t op);
void CPY(uint8_t op);
void BCC(uint8_t op);
void BCS(uint8_t op);
void BEQ(uint8_t op);
void BMI(uint8_t op);
void BNE(uint8_t op);
void BPL(uint8_t op);
void BVC(uint8_t op);
void BVS(uint8_t op);
void JMP(uint16_t op);
void JSR(uint16_t op);
void RTS();
void BRK();
void RTI();
void BIT(uint8_t op);
void NOP();

// high 0
void ix00();
void ix01();
void ix05();
void ix06();
void ix08();
void ix09();
void ix0a();
void ix0d();
void ix0e();

// high 1
void ix10();
void ix11();
void ix15();
void ix16();
void ix18();
void ix19();
void ix1d();
void ix1e();

// high 2
void ix20();
void ix21();
void ix24();
void ix25();
void ix26();
void ix28();
void ix29();
void ix2a();
void ix2c();
void ix2d();
void ix2e();

// high 3
void ix30();
void ix31();
void ix35();
void ix36();
void ix38();
void ix39();
void ix3d();
void ix3e();

// high 4
void ix40();
void ix41();
void ix45();
void ix46();
void ix48();
void ix49();
void ix4a();
void ix4c();
void ix4d();
void ix4e();

// high 5
void ix50();
void ix51();
void ix55();
void ix56();
void ix58();
void ix59();
void ix5d();
void ix5e();

// high 6
void ix60();
void ix61();
void ix65();
void ix66();
void ix68();
void ix69();
void ix6a();
void ix6c();
void ix6d();
void ix6e();

// high 7
void ix70();
void ix71();
void ix75();
void ix76();
void ix78();
void ix79();
void ix7d();
void ix7e();

// high 8
void ix81();
void ix84();
void ix85();
void ix86();
void ix88();
void ix8a();
void ix8c();
void ix8d();
void ix8e();

// high 9
void ix90();
void ix91();
void ix94();
void ix95();
void ix96();
void ix98();
void ix99();
void ix9a();
void ix9d();

// high A
void ixa0();
void ixa1();
void ixa2();
void ixa4();
void ixa5();
void ixa6();
void ixa8();
void ixa9();
void ixaa();
void ixac();
void ixad();
void ixae();

// high B
void ixb0();
void ixb1();
void ixb4();
void ixb5();
void ixb6();
void ixb8();
void ixb9();
void ixba();
void ixbc();
void ixbd();
void ixbe();

// high C
void ixc0();
void ixc1();
void ixc4();
void ixc5();
void ixc6();
void ixc8();
void ixc9();
void ixca();
void ixcc();
void ixcd();
void ixce();

// high D
void ixd0();
void ixd1();
void ixd5();
void ixd6();
void ixd8();
void ixd9();
void ixdd();
void ixde();

// high E
void ixe0();
void ixe1();
void ixe4();
void ixe5();
void ixe6();
void ixe8();
void ixe9();
void ixea();
void ixec();
void ixed();
void ixee();

// high F
void ixf0();
void ixf1();
void ixf5();
void ixf6();
void ixf8();
void ixf9();
void ixfd();
void ixfe();

#endif