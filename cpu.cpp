#include "cpu.h"

CPU::CPU()
{
	init();
}

// Initialize CPU internal data structures
void CPU::init()
{
	// Program Counter is initialized to $100
	// Stack Pointer is initialized to $FFFE

	// set meaningless register values for opcode debugging
	reg_A = 0;
	reg_B = 0;
	reg_C = 0;
	reg_D = 0;
	reg_E = 0;
	reg_F = 0;
	reg_H = 0;
	reg_L = 0;
	reg_SP = 0;
	reg_PC = 0;
}

// Reproduces the effect of a reset signal sent to the CPU
void CPU::reset()
{
}

// Start emulation of CPU
void CPU::execute(int cycles)
{
}

void CPU::interrupt_signal()
{
}

void CPU::stop()
{
}

Address CPU::address(Byte high, Byte low)
{
	return (high << 8 | low);
}

void CPU::debug()
{
	parse_opcode(0x4E);
}

int CPU::parse_opcode(Opcode code)
{
	int opbytes = 1;

	unsigned char value = 195;

	unsigned char addr1 = 0b00000000;
	unsigned char addr2 = 0b00000010;

	reg_H = addr1;
	reg_L = addr2;

	switch (code)
	{
		// 65
		case 0x06: LD(reg_B, value); opbytes = 2; break;
		case 0x0E: LD(reg_C, value); opbytes = 2; break;
		case 0x16: LD(reg_D, value); opbytes = 2; break;
		case 0x1E: LD(reg_E, value); opbytes = 2; break;
		case 0x26: LD(reg_H, value); opbytes = 2; break;
		case 0x2E: LD(reg_L, value); opbytes = 2; break;
		// 66
		case 0x7F: LD(reg_A, reg_A); break;
		case 0x78: LD(reg_A, reg_B); break;
		case 0x79: LD(reg_A, reg_C); break;
		case 0x7A: LD(reg_A, reg_D); break;
		case 0x7B: LD(reg_A, reg_E); break;
		case 0x7C: LD(reg_A, reg_H); break;
		case 0x7D: LD(reg_A, reg_L); break;
		case 0x7E: LD(reg_A, address(reg_H, reg_L)); break;
		case 0x40: LD(reg_B, reg_B); break;
		case 0x41: LD(reg_B, reg_C); break;
		case 0x42: LD(reg_B, reg_D); break;
		case 0x43: LD(reg_B, reg_E); break;
		case 0x44: LD(reg_B, reg_H); break;
		case 0x45: LD(reg_B, reg_L); break;
		case 0x46: LD(reg_B, address(reg_H, reg_L)); break;
		case 0x48: LD(reg_C, reg_B); break;
		case 0x49: LD(reg_C, reg_C); break;
		case 0x4A: LD(reg_C, reg_D); break;
		case 0x4B: LD(reg_C, reg_E); break;
		case 0x4C: LD(reg_C, reg_H); break;
		case 0x4D: LD(reg_C, reg_L); break;
		case 0x4E: LD(reg_C, address(reg_H, reg_L)); break;
		case 0x50: LD(reg_D, reg_B); break;
		case 0x51: LD(reg_D, reg_C); break;
		// 67
		case 0x52: LD(reg_D, reg_D); break;
		case 0x53: LD(reg_D, reg_E); break;
		case 0x54: LD(reg_D, reg_H); break;
		case 0x55: LD(reg_D, reg_L); break;
		case 0x56: LD(reg_D, address(reg_H, reg_L)); break;
		case 0x58: LD(reg_E, reg_B); break;
		case 0x59: LD(reg_E, reg_C); break;
		case 0x5A: LD(reg_E, reg_D); break;
		case 0x5B: LD(reg_E, reg_E); break;
		case 0x5C: LD(reg_E, reg_H); break;
		case 0x5D: LD(reg_E, reg_L); break;
		case 0x5E: LD(reg_E, address(reg_H, reg_L)); break;
		case 0x60: LD(reg_H, reg_B); break;
		case 0x61: LD(reg_H, reg_C); break;

		case 0x62: LD(reg_H, reg_D); break;
		case 0x63: LD(reg_H, reg_E); break;
		case 0x64: LD(reg_H, reg_H); break;
		case 0x65: LD(reg_H, reg_L); break;
		case 0x66: LD(reg_H, address(reg_H, reg_L)); break;
		case 0x68: LD(reg_L, reg_B); break;
		case 0x69: LD(reg_L, reg_C); break;
		case 0x6A: LD(reg_L, reg_D); break;
		case 0x6B: LD(reg_L, reg_E); break;
		case 0x6C: LD(reg_L, reg_H); break;
		case 0x6D: LD(reg_L, reg_L); break;
		case 0x6E: LD(reg_L, address(reg_H, reg_L)); break;

		case 0x70: LD(address(reg_H, reg_L), reg_C); break;
		case 0x71: LD(reg_H, reg_C); break;
		case 0x72: LD(reg_H, reg_C); break;
		case 0x73: LD(reg_H, reg_C); break;
		case 0x74: LD(reg_H, reg_C); break;
		case 0x75: LD(reg_H, reg_C); break;
		case 0x36: LD(reg_H, reg_C); break;
	}

	return opbytes;
}

void CPU::LD(Byte& destination, Byte value)
{
	destination = value;
}

void CPU::LD(Byte& destination, Address addr)
{
	destination = memory.read(addr);
}

void CPU::LD(Address addr, Byte value)
{
	memory.write(addr, value);
}