#ifndef __INS
#define __INS

// by name
extern void LDA(int8_t op);
extern void LDX(int8_t op);
extern void LDY(int8_t op);
extern void STA(int16_t op);
extern void STX(int16_t op);
extern void STY(int16_t op);
extern void TAX();
extern void TAY();
extern void TSX();
extern void TXA();
extern void TXS();
extern void TYA();
extern void PHA();
extern void PHP();
extern void PLA();
extern void PLP();
extern void DEC(int16_t op);
extern void DEX();
extern void DEY();
extern void INC(int16_t op);
extern void INX();
extern void INY();
extern void ADC(int8_t op);
extern void SBC(int8_t op);
extern void AND(int8_t op);
extern void EOR(int8_t op);
extern void ORA(int8_t op);
extern void ASL(int8_t op);
extern void LSR(int8_t op);
extern void ROL(int8_t op);
extern void ROR(int8_t op);
extern void CLC();
extern void CLD();
extern void CLI();
extern void CLV();
extern void SEC();
extern void SED();
extern void SEI();
extern void CMP(int8_t op);
extern void CPX(int8_t op);
extern void CPY(int8_t op);
extern void BCC(int8_t op);
extern void BCS(int8_t op);
extern void BEQ(int8_t op);
extern void BMI(int8_t op);
extern void BNE(int8_t op);
extern void BPL(int8_t op);
extern void BVC(int8_t op);
extern void BVS(int8_t op);
extern void JMP(int16_t op);
extern void JSR(int16_t op);
extern void RTS();
extern void BRK();
extern void RTI();
extern void BIT(int8_t op);
extern void NOP();

// high 0
extern void ix00();
extern void ix01();
extern void ix05();
extern void ix06();
extern void ix08();
extern void ix09();
extern void ix0a();
extern void ix0d();
extern void ix0e();

// high 1
extern void ix10();
extern void ix11();
extern void ix15();
extern void ix16();
extern void ix18();
extern void ix19();
extern void ix1d();
extern void ix1e();

// high 2
extern void ix20();
extern void ix21();
extern void ix24();
extern void ix25();
extern void ix26();
extern void ix28();
extern void ix29();
extern void ix2a();
extern void ix2c();
extern void ix2d();
extern void ix2e();

// high 3
extern void ix30();
extern void ix31();
extern void ix35();
extern void ix36();
extern void ix38();
extern void ix39();
extern void ix3d();
extern void ix3e();

// high 4
extern void ix40();
extern void ix41();
extern void ix45();
extern void ix46();
extern void ix48();
extern void ix49();
extern void ix4a();
extern void ix4c();
extern void ix4d();
extern void ix4e();

// high 5
extern void ix50();
extern void ix51();
extern void ix55();
extern void ix56();
extern void ix58();
extern void ix59();
extern void ix5d();
extern void ix5e();

// high 6
extern void ix60();
extern void ix61();
extern void ix65();
extern void ix66();
extern void ix68();
extern void ix69();
extern void ix6a();
extern void ix6c();
extern void ix6d();
extern void ix6e();

// high 7
extern void ix70();
extern void ix71();
extern void ix75();
extern void ix76();
extern void ix78();
extern void ix79();
extern void ix7d();
extern void ix7e();

// high 8
extern void ix81();
extern void ix84();
extern void ix85();
extern void ix86();
extern void ix88();
extern void ix8a();
extern void ix8c();
extern void ix8d();
extern void ix8e();

// high 9
extern void ix90();
extern void ix91();
extern void ix94();
extern void ix95();
extern void ix96();
extern void ix98();
extern void ix99();
extern void ix9a();
extern void ix9d();

// high A
extern void ixa0();
extern void ixa1();
extern void ixa2();
extern void ixa4();
extern void ixa5();
extern void ixa6();
extern void ixa8();
extern void ixa9();
extern void ixaa();
extern void ixac();
extern void ixad();
extern void ixae();

// high B
extern void ixb0();
extern void ixb1();
extern void ixb4();
extern void ixb5();
extern void ixb6();
extern void ixb8();
extern void ixb9();
extern void ixba();
extern void ixbc();
extern void ixbd();
extern void ixbe();

// high C
extern void ixc0();
extern void ixc1();
extern void ixc4();
extern void ixc5();
extern void ixc6();
extern void ixc8();
extern void ixc9();
extern void ixca();
extern void ixcc();
extern void ixcd();
extern void ixce();

// high D
extern void ixd0();
extern void ixd1();
extern void ixd5();
extern void ixd6();
extern void ixd8();
extern void ixd9();
extern void ixdd();
extern void ixde();

// high E
extern void ixe0();
extern void ixe1();
extern void ixe4();
extern void ixe5();
extern void ixe6();
extern void ixe8();
extern void ixe9();
extern void ixea();
extern void ixec();
extern void ixed();
extern void ixee();

// high F
extern void ixf0();
extern void ixf1();
extern void ixf5();
extern void ixf6();
extern void ixf8();
extern void ixf9();
extern void ixfd();
extern void ixfe();

// by name
extern void ORA(int8_t op);

#endif