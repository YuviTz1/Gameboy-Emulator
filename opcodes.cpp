#include "cpu.h"


void CPU::parse_bit_op(Opcode code)
{
	switch (code)
	{
		case 0x07: RL(reg_A, false, true); break;
		case 0x00: RL(reg_B, false, true); break;
		case 0x01: RL(reg_C, false, true); break;
		case 0x02: RL(reg_D, false, true); break;
		case 0x03: RL(reg_E, false, true); break;
		case 0x04: RL(reg_H, false, true); break;
		case 0x05: RL(reg_L, false, true); break;
		case 0x06: RL(Pair(reg_H, reg_L).address(), false); break;
		case 0x17: RL(reg_A, true, true); break;
		case 0x10: RL(reg_B, true, true); break;
		case 0x11: RL(reg_C, true, true); break;
		case 0x12: RL(reg_D, true, true); break;
		case 0x13: RL(reg_E, true, true); break;
		case 0x14: RL(reg_H, true, true); break;
		case 0x15: RL(reg_L, true, true); break;
		case 0x16: RL(Pair(reg_H, reg_L).address(), true); break;

		case 0x0F: RR(reg_A, false, true); break;
		case 0x08: RR(reg_B, false, true); break;
		case 0x09: RR(reg_C, false, true); break;
		case 0x0A: RR(reg_D, false, true); break;
		case 0x0B: RR(reg_E, false, true); break;
		case 0x0C: RR(reg_H, false, true); break;
		case 0x0D: RR(reg_L, false, true); break;
		case 0x0E: RR(Pair(reg_H, reg_L).address(), false); break;
		case 0x1F: RR(reg_A, true, true); break;
		case 0x18: RR(reg_B, true, true); break;
		case 0x19: RR(reg_C, true, true); break;
		case 0x1A: RR(reg_D, true, true); break;
		case 0x1B: RR(reg_E, true, true); break;
		case 0x1C: RR(reg_H, true, true); break;
		case 0x1D: RR(reg_L, true, true); break;
		case 0x1E: RR(Pair(reg_H, reg_L).address(), false); break; // this could actually have a different beginning opcode, check manual

		case 0x27: SLA(reg_A); break;
		case 0x20: SLA(reg_B); break;
		case 0x21: SLA(reg_C); break;
		case 0x22: SLA(reg_D); break;
		case 0x23: SLA(reg_E); break;
		case 0x24: SLA(reg_H); break;
		case 0x25: SLA(reg_L); break;
		case 0x26: SLA(Pair(reg_H, reg_L).address()); break; // this could actually have a different beginning opcode, check manual

		case 0x2F: SRA(reg_A); break;
		case 0x28: SRA(reg_B); break;
		case 0x29: SRA(reg_C); break;
		case 0x2A: SRA(reg_D); break;
		case 0x2B: SRA(reg_E); break;
		case 0x2C: SRA(reg_H); break;
		case 0x2D: SRA(reg_L); break;
		case 0x2E: SRA(Pair(reg_H, reg_L).address()); break;

		case 0x3F: SRL(reg_A); break;
		case 0x38: SRL(reg_B); break;
		case 0x39: SRL(reg_C); break;
		case 0x3A: SRL(reg_D); break;
		case 0x3B: SRL(reg_E); break;
		case 0x3C: SRL(reg_H); break;
		case 0x3D: SRL(reg_L); break;
		case 0x3E: SRL(Pair(reg_H, reg_L).address()); break;

		case 0x37: SWAP(reg_A); break;
		case 0x30: SWAP(reg_B); break;
		case 0x31: SWAP(reg_C); break;
		case 0x32: SWAP(reg_D); break;
		case 0x33: SWAP(reg_E); break;
		case 0x34: SWAP(reg_H); break;
		case 0x35: SWAP(reg_L); break;
		case 0x36: SWAP(Pair(reg_H, reg_L).address()); break;

		case 0x47: BIT(reg_A, 0); break;
		case 0x4F: BIT(reg_A, 1); break;
		case 0x57: BIT(reg_A, 2); break;
		case 0x5F: BIT(reg_A, 3); break;
		case 0x67: BIT(reg_A, 4); break;
		case 0x6F: BIT(reg_A, 5); break;
		case 0x77: BIT(reg_A, 6); break;
		case 0x7F: BIT(reg_A, 7); break;
		case 0x40: BIT(reg_B, 0); break;
		case 0x48: BIT(reg_B, 1); break;
		case 0x50: BIT(reg_B, 2); break;
		case 0x58: BIT(reg_B, 3); break;
		case 0x60: BIT(reg_B, 4); break;
		case 0x68: BIT(reg_B, 5); break;
		case 0x70: BIT(reg_B, 6); break;
		case 0x78: BIT(reg_B, 7); break;
		case 0x41: BIT(reg_C, 0); break;
		case 0x49: BIT(reg_C, 1); break;
		case 0x51: BIT(reg_C, 2); break;
		case 0x59: BIT(reg_C, 3); break;
		case 0x61: BIT(reg_C, 4); break;
		case 0x69: BIT(reg_C, 5); break;
		case 0x71: BIT(reg_C, 6); break;
		case 0x79: BIT(reg_C, 7); break;
		case 0x42: BIT(reg_D, 0); break;
		case 0x4A: BIT(reg_D, 1); break;
		case 0x52: BIT(reg_D, 2); break;
		case 0x5A: BIT(reg_D, 3); break;
		case 0x62: BIT(reg_D, 4); break;
		case 0x6A: BIT(reg_D, 5); break;
		case 0x72: BIT(reg_D, 6); break;
		case 0x7A: BIT(reg_D, 7); break;
		case 0x43: BIT(reg_E, 0); break;
		case 0x4B: BIT(reg_E, 1); break;
		case 0x53: BIT(reg_E, 2); break;
		case 0x5B: BIT(reg_E, 3); break;
		case 0x63: BIT(reg_E, 4); break;
		case 0x6B: BIT(reg_E, 5); break;
		case 0x73: BIT(reg_E, 6); break;
		case 0x7B: BIT(reg_E, 7); break;
		case 0x44: BIT(reg_H, 0); break;
		case 0x4C: BIT(reg_H, 1); break;
		case 0x54: BIT(reg_H, 2); break;
		case 0x5C: BIT(reg_H, 3); break;
		case 0x64: BIT(reg_H, 4); break;
		case 0x6C: BIT(reg_H, 5); break;
		case 0x74: BIT(reg_H, 6); break;
		case 0x7C: BIT(reg_H, 7); break;
		case 0x45: BIT(reg_L, 0); break;
		case 0x4D: BIT(reg_L, 1); break;
		case 0x55: BIT(reg_L, 2); break;
		case 0x5D: BIT(reg_L, 3); break;
		case 0x65: BIT(reg_L, 4); break;
		case 0x6D: BIT(reg_L, 5); break;
		case 0x75: BIT(reg_L, 6); break;
		case 0x7D: BIT(reg_L, 7); break;
		case 0x46: BIT(Pair(reg_H, reg_L).address(), 0); break;
		case 0x4E: BIT(Pair(reg_H, reg_L).address(), 1); break;
		case 0x56: BIT(Pair(reg_H, reg_L).address(), 2); break;
		case 0x5E: BIT(Pair(reg_H, reg_L).address(), 3); break;
		case 0x66: BIT(Pair(reg_H, reg_L).address(), 4); break;
		case 0x6E: BIT(Pair(reg_H, reg_L).address(), 5); break;
		case 0x76: BIT(Pair(reg_H, reg_L).address(), 6); break;
		case 0x7E: BIT(Pair(reg_H, reg_L).address(), 7); break;

		case 0xC7: SET(reg_A, 0); break;
		case 0xCF: SET(reg_A, 1); break;
		case 0xD7: SET(reg_A, 2); break;
		case 0xDF: SET(reg_A, 3); break;
		case 0xE7: SET(reg_A, 4); break;
		case 0xEF: SET(reg_A, 5); break;
		case 0xF7: SET(reg_A, 6); break;
		case 0xFF: SET(reg_A, 7); break;
		case 0xC0: SET(reg_B, 0); break;
		case 0xC8: SET(reg_B, 1); break;
		case 0xD0: SET(reg_B, 2); break;
		case 0xD8: SET(reg_B, 3); break;
		case 0xE0: SET(reg_B, 4); break;
		case 0xE8: SET(reg_B, 5); break;
		case 0xF0: SET(reg_B, 6); break;
		case 0xF8: SET(reg_B, 7); break;
		case 0xC1: SET(reg_C, 0); break;
		case 0xC9: SET(reg_C, 1); break;
		case 0xD1: SET(reg_C, 2); break;
		case 0xD9: SET(reg_C, 3); break;
		case 0xE1: SET(reg_C, 4); break;
		case 0xE9: SET(reg_C, 5); break;
		case 0xF1: SET(reg_C, 6); break;
		case 0xF9: SET(reg_C, 7); break;
		case 0xC2: SET(reg_D, 0); break;
		case 0xCA: SET(reg_D, 1); break;
		case 0xD2: SET(reg_D, 2); break;
		case 0xDA: SET(reg_D, 3); break;
		case 0xE2: SET(reg_D, 4); break;
		case 0xEA: SET(reg_D, 5); break;
		case 0xF2: SET(reg_D, 6); break;
		case 0xFA: SET(reg_D, 7); break;
		case 0xC3: SET(reg_E, 0); break;
		case 0xCB: SET(reg_E, 1); break;
		case 0xD3: SET(reg_E, 2); break;
		case 0xDB: SET(reg_E, 3); break;
		case 0xE3: SET(reg_E, 4); break;
		case 0xEB: SET(reg_E, 5); break;
		case 0xF3: SET(reg_E, 6); break;
		case 0xFB: SET(reg_E, 7); break;
		case 0xC4: SET(reg_H, 0); break;
		case 0xCC: SET(reg_H, 1); break;
		case 0xD4: SET(reg_H, 2); break;
		case 0xDC: SET(reg_H, 3); break;
		case 0xE4: SET(reg_H, 4); break;
		case 0xEC: SET(reg_H, 5); break;
		case 0xF4: SET(reg_H, 6); break;
		case 0xFC: SET(reg_H, 7); break;
		case 0xC5: SET(reg_L, 0); break;
		case 0xCD: SET(reg_L, 1); break;
		case 0xD5: SET(reg_L, 2); break;
		case 0xDD: SET(reg_L, 3); break;
		case 0xE5: SET(reg_L, 4); break;
		case 0xED: SET(reg_L, 5); break;
		case 0xF5: SET(reg_L, 6); break;
		case 0xFD: SET(reg_L, 7); break;
		case 0xC6: SET(Pair(reg_H, reg_L).address(), 0); break;
		case 0xCE: SET(Pair(reg_H, reg_L).address(), 1); break;
		case 0xD6: SET(Pair(reg_H, reg_L).address(), 2); break;
		case 0xDE: SET(Pair(reg_H, reg_L).address(), 3); break;
		case 0xE6: SET(Pair(reg_H, reg_L).address(), 4); break;
		case 0xEE: SET(Pair(reg_H, reg_L).address(), 5); break;
		case 0xF6: SET(Pair(reg_H, reg_L).address(), 6); break;
		case 0xFE: SET(Pair(reg_H, reg_L).address(), 7); break;

		case 0x87: RES(reg_A, 0); break;
		case 0x8F: RES(reg_A, 1); break;
		case 0x97: RES(reg_A, 2); break;
		case 0x9F: RES(reg_A, 3); break;
		case 0xA7: RES(reg_A, 4); break;
		case 0xAF: RES(reg_A, 5); break;
		case 0xB7: RES(reg_A, 6); break;
		case 0xBF: RES(reg_A, 7); break;
		case 0x80: RES(reg_B, 0); break;
		case 0x88: RES(reg_B, 1); break;
		case 0x90: RES(reg_B, 2); break;
		case 0x98: RES(reg_B, 3); break;
		case 0xA0: RES(reg_B, 4); break;
		case 0xA8: RES(reg_B, 5); break;
		case 0xB0: RES(reg_B, 6); break;
		case 0xB8: RES(reg_B, 7); break;
		case 0x81: RES(reg_C, 0); break;
		case 0x89: RES(reg_C, 1); break;
		case 0x91: RES(reg_C, 2); break;
		case 0x99: RES(reg_C, 3); break;
		case 0xA1: RES(reg_C, 4); break;
		case 0xA9: RES(reg_C, 5); break;
		case 0xB1: RES(reg_C, 6); break;
		case 0xB9: RES(reg_C, 7); break;
		case 0x82: RES(reg_D, 0); break;
		case 0x8A: RES(reg_D, 1); break;
		case 0x92: RES(reg_D, 2); break;
		case 0x9A: RES(reg_D, 3); break;
		case 0xA2: RES(reg_D, 4); break;
		case 0xAA: RES(reg_D, 5); break;
		case 0xB2: RES(reg_D, 6); break;
		case 0xBA: RES(reg_D, 7); break;
		case 0x83: RES(reg_E, 0); break;
		case 0x8B: RES(reg_E, 1); break;
		case 0x93: RES(reg_E, 2); break;
		case 0x9B: RES(reg_E, 3); break;
		case 0xA3: RES(reg_E, 4); break;
		case 0xAB: RES(reg_E, 5); break;
		case 0xB3: RES(reg_E, 6); break;
		case 0xBB: RES(reg_E, 7); break;
		case 0x84: RES(reg_H, 0); break;
		case 0x8C: RES(reg_H, 1); break;
		case 0x94: RES(reg_H, 2); break;
		case 0x9C: RES(reg_H, 3); break;
		case 0xA4: RES(reg_H, 4); break;
		case 0xAC: RES(reg_H, 5); break;
		case 0xB4: RES(reg_H, 6); break;
		case 0xBC: RES(reg_H, 7); break;
		case 0x85: RES(reg_L, 0); break;
		case 0x8D: RES(reg_L, 1); break;
		case 0x95: RES(reg_L, 2); break;
		case 0x9D: RES(reg_L, 3); break;
		case 0xA5: RES(reg_L, 4); break;
		case 0xAD: RES(reg_L, 5); break;
		case 0xB5: RES(reg_L, 6); break;
		case 0xBD: RES(reg_L, 7); break;
		case 0x86: RES(Pair(reg_H, reg_L).address(), 0); break;
		case 0x8E: RES(Pair(reg_H, reg_L).address(), 1); break;
		case 0x96: RES(Pair(reg_H, reg_L).address(), 2); break;
		case 0x9E: RES(Pair(reg_H, reg_L).address(), 3); break;
		case 0xA6: RES(Pair(reg_H, reg_L).address(), 4); break;
		case 0xAE: RES(Pair(reg_H, reg_L).address(), 5); break;
		case 0xB6: RES(Pair(reg_H, reg_L).address(), 6); break;
		case 0xBE: RES(Pair(reg_H, reg_L).address(), 7); break;
	}
}

int CPU::parse_opcode(Opcode code)
{
	int opbytes = 1;

	Byte value = 0x8F;
	Byte value2 = 1;

	// REG_D could possibly be incorrect, assumed current value from manual to match GBCPUman
	switch (code)
	{
		// 85
		case 0x7F: LD(reg_A, reg_A); break;
		case 0x78: LD(reg_A, reg_B); break;
		case 0x79: LD(reg_A, reg_C); break;
		case 0x7A: LD(reg_A, reg_D); break;
		case 0x7B: LD(reg_A, reg_E); break;
		case 0x7C: LD(reg_A, reg_H); break;
		case 0x7D: LD(reg_A, reg_L); break;
		case 0x47: LD(reg_B, reg_A); break;
		case 0x40: LD(reg_B, reg_B); break;
		case 0x41: LD(reg_B, reg_C); break;
		case 0x42: LD(reg_B, reg_D); break;
		case 0x43: LD(reg_B, reg_E); break;
		case 0x44: LD(reg_B, reg_H); break;
		case 0x45: LD(reg_B, reg_L); break;
		case 0x4F: LD(reg_C, reg_A); break;
		case 0x48: LD(reg_C, reg_B); break;
		case 0x49: LD(reg_C, reg_C); break;
		case 0x4A: LD(reg_C, reg_D); break;
		case 0x4B: LD(reg_C, reg_E); break;
		case 0x4C: LD(reg_C, reg_H); break;
		case 0x4D: LD(reg_C, reg_L); break;
		case 0x57: LD(reg_D, reg_A); break;
		case 0x50: LD(reg_D, reg_B); break;
		case 0x51: LD(reg_D, reg_C); break;
		case 0x52: LD(reg_D, reg_D); break;
		case 0x53: LD(reg_D, reg_E); break;
		case 0x54: LD(reg_D, reg_H); break;
		case 0x55: LD(reg_D, reg_L); break;
		case 0x5F: LD(reg_E, reg_A); break;
		case 0x58: LD(reg_E, reg_B); break;
		case 0x59: LD(reg_E, reg_C); break;
		case 0x5A: LD(reg_E, reg_D); break;
		case 0x5B: LD(reg_E, reg_E); break;
		case 0x5C: LD(reg_E, reg_H); break;
		case 0x5D: LD(reg_E, reg_L); break;
		case 0x67: LD(reg_H, reg_A); break;
		case 0x60: LD(reg_H, reg_B); break;
		case 0x61: LD(reg_H, reg_C); break;
		case 0x62: LD(reg_H, reg_D); break;
		case 0x63: LD(reg_H, reg_E); break;
		case 0x64: LD(reg_H, reg_H); break;
		case 0x65: LD(reg_H, reg_L); break;
		case 0x6F: LD(reg_L, reg_A); break;
		case 0x68: LD(reg_L, reg_B); break;
		case 0x69: LD(reg_L, reg_C); break;
		case 0x6A: LD(reg_L, reg_D); break;
		case 0x6B: LD(reg_L, reg_E); break;
		case 0x6C: LD(reg_L, reg_H); break;
		case 0x6D: LD(reg_L, reg_L); break;
		case 0x3E: LD(reg_A, value); opbytes = 2; break;
		case 0x06: LD(reg_B, value); opbytes = 2; break;
		case 0x0E: LD(reg_C, value); opbytes = 2; break;
		case 0x16: LD(reg_D, value); opbytes = 2; break;
		case 0x1E: LD(reg_E, value); opbytes = 2; break;
		case 0x26: LD(reg_H, value); opbytes = 2; break;
		case 0x2E: LD(reg_L, value); opbytes = 2; break;
		case 0x7E: LD(reg_A, Pair(reg_H, reg_L).address()); break;
		case 0x46: LD(reg_B, Pair(reg_H, reg_L).address()); break;
		case 0x4E: LD(reg_C, Pair(reg_H, reg_L).address()); break;
		case 0x56: LD(reg_D, Pair(reg_H, reg_L).address()); break;
		case 0x5E: LD(reg_E, Pair(reg_H, reg_L).address()); break;
		case 0x66: LD(reg_H, Pair(reg_H, reg_L).address()); break;
		case 0x6E: LD(reg_L, Pair(reg_H, reg_L).address()); break;
		// 86
		case 0x77: LD(Pair(reg_H, reg_L).address(), reg_A); break;
		case 0x70: LD(Pair(reg_H, reg_L).address(), reg_B); break;
		case 0x71: LD(Pair(reg_H, reg_L).address(), reg_C); break;
		case 0x72: LD(Pair(reg_H, reg_L).address(), reg_D); break;
		case 0x73: LD(Pair(reg_H, reg_L).address(), reg_E); break;
		case 0x74: LD(Pair(reg_H, reg_L).address(), reg_H); break;
		case 0x75: LD(Pair(reg_H, reg_L).address(), reg_L); break;
		case 0x36: LD(Pair(reg_H, reg_L).address(), value); opbytes = 2; break;
		case 0x0A: LD(Pair(reg_B, reg_C).address(), value); opbytes = 2; break;
		case 0x1A: LD(Pair(reg_D, reg_E).address(), value); opbytes = 2; break;
		case 0xF2: LD(reg_A, (Address)(0xFF00 + reg_C)); break;
		// 87
		case 0xE2: LD((Address)(0xFF00 + reg_C), reg_A); break;
		case 0xF0: LD(reg_A, (Address)(0xFF00 + value)); break;
		case 0xE0: LD((Address)(0xFF00 + value), reg_A); break;
		case 0xFA: LD(reg_A, Pair(value, value2).address()); opbytes = 3; break;
		// 88
		case 0xEA: LD(Pair(value, value2).address(), reg_A); opbytes = 3; break;
		case 0x2A: LD(reg_A, Pair(reg_H, reg_L).address()); Pair(reg_H, reg_L).inc(); break;
		case 0x3A: LD(reg_A, Pair(reg_H, reg_L).address()); Pair(reg_H, reg_L).dec(); break;
		case 0x02: LD(Pair(reg_B, reg_C).address(), reg_A); break;
		case 0x12: LD(Pair(reg_D, reg_E).address(), reg_A); break;
		// 89
		case 0x22: LD(Pair(reg_H, reg_L).address(), reg_A); Pair(reg_H, reg_L).inc(); break;
		case 0x32: LD(Pair(reg_H, reg_L).address(), reg_A); Pair(reg_H, reg_L).dec(); break;
		// 90
		case 0x01: LD(Pair(reg_B, reg_C), value, value2); opbytes = 3; break;
		case 0x11: LD(Pair(reg_D, reg_E), value, value2); opbytes = 3; break; // says DD in nintindo manual, assumed DE pair
		case 0x21: LD(Pair(reg_H, reg_L), value, value2); opbytes = 3; break;
		case 0x31: LD(reg_SP, value, value2); opbytes = 3; break;
		case 0xF9: LD(reg_SP, reg_H, reg_L); break;
		case 0xC5: PUSH(reg_B, reg_C); break;
		case 0xD5: PUSH(reg_D, reg_E); break;
		case 0xE5: PUSH(reg_H, reg_L); break;
		case 0xF5: PUSH(reg_A, reg_F); break;
		// 91
		case 0xC1: POP(reg_B, reg_C); break;
		case 0xD1: POP(reg_D, reg_E); break;
		case 0xE1: POP(reg_H, reg_L); break;
		case 0xF1: POP(reg_A, reg_F); break;
		case 0xF8: LDHL(value); opbytes = 2; break;
		case 0x08: LDNN(value, value2); opbytes = 3; break;
		// 92
		case 0x87: ADD(reg_A, reg_A); break;
		case 0x80: ADD(reg_A, reg_B); break;
		case 0x81: ADD(reg_A, reg_C); break;
		case 0x82: ADD(reg_A, reg_D); break;
		case 0x83: ADD(reg_A, reg_E); break;
		case 0x84: ADD(reg_A, reg_H); break;
		case 0x85: ADD(reg_A, reg_L); break;
		case 0xC6: ADD(reg_A, value); opbytes = 2; break;
		case 0x86: ADD(reg_A, Pair(reg_H, reg_L).address()); break;
		case 0x8F: ADC(reg_A, reg_A); break;
		case 0x88: ADC(reg_A, reg_B); break;
		case 0x89: ADC(reg_A, reg_C); break;
		case 0x8A: ADC(reg_A, reg_D); break;
		case 0x8B: ADC(reg_A, reg_E); break;
		case 0x8C: ADC(reg_A, reg_H); break;
		case 0x8D: ADC(reg_A, reg_L); break;
		case 0xCE: ADC(reg_A, value); opbytes = 2; break;
		case 0x8E: ADC(reg_A, Pair(reg_H, reg_L).address()); break;
		// 93
		case 0x97: SUB(reg_A, reg_A); break;
		case 0x90: SUB(reg_A, reg_B); break;
		case 0x91: SUB(reg_A, reg_C); break;
		case 0x92: SUB(reg_A, reg_D); break;
		case 0x93: SUB(reg_A, reg_E); break;
		case 0x94: SUB(reg_A, reg_H); break;
		case 0x95: SUB(reg_A, reg_L); break;
		case 0xD6: SUB(reg_A, value); opbytes = 2; break;
		case 0x96: SUB(reg_A, Pair(reg_H, reg_L).address()); break;
		case 0x9F: SBC(reg_A, reg_A); break;
		case 0x98: SBC(reg_A, reg_B); break;
		case 0x99: SBC(reg_A, reg_C); break;
		case 0x9A: SBC(reg_A, reg_D); break;
		case 0x9B: SBC(reg_A, reg_E); break;
		case 0x9C: SBC(reg_A, reg_H); break;
		case 0x9D: SBC(reg_A, reg_L); break;
		case 0xDE: SBC(reg_A, value); opbytes = 2; break;
		case 0x9E: SBC(reg_A, Pair(reg_H, reg_L).address()); break;
		// 94
		case 0xA7: AND(reg_A, reg_A); break;
		case 0xA0: AND(reg_A, reg_B); break;
		case 0xA1: AND(reg_A, reg_C); break;
		case 0xA2: AND(reg_A, reg_D); break;
		case 0xA3: AND(reg_A, reg_E); break;
		case 0xA4: AND(reg_A, reg_H); break;
		case 0xA5: AND(reg_A, reg_L); break;
		case 0xE6: AND(reg_A, value); break;
		case 0xA6: AND(reg_A, Pair(reg_H, reg_L).address()); break;
		case 0xB7: OR(reg_A, reg_A); break;
		case 0xB0: OR(reg_A, reg_B); break;
		case 0xB1: OR(reg_A, reg_C); break;
		case 0xB2: OR(reg_A, reg_D); break;
		case 0xB3: OR(reg_A, reg_E); break;
		case 0xB4: OR(reg_A, reg_H); break;
		case 0xB5: OR(reg_A, reg_L); break;
		case 0xF6: OR(reg_A, value); opbytes = 2; break;
		case 0xB6: OR(reg_A, Pair(reg_H, reg_L).address()); break;
		case 0xAF: XOR(reg_A, reg_A); break;
		case 0xA8: XOR(reg_A, reg_B); break;
		case 0xA9: XOR(reg_A, reg_C); break;
		case 0xAA: XOR(reg_A, reg_D); break;
		case 0xAB: XOR(reg_A, reg_E); break;
		case 0xAC: XOR(reg_A, reg_H); break;
		case 0xAD: XOR(reg_A, reg_L); break;
		case 0xEE: XOR(reg_A, value); opbytes = 2; break;
		case 0xAE: XOR(reg_A, Pair(reg_H, reg_L).address()); break;
		// 95 - 96
		case 0xBF: CP(reg_A, reg_A); break;
		case 0xB8: CP(reg_A, reg_B); break;
		case 0xB9: CP(reg_A, reg_C); break;
		case 0xBA: CP(reg_A, reg_D); break;
		case 0xBB: CP(reg_A, reg_E); break;
		case 0xBC: CP(reg_A, reg_H); break;
		case 0xBD: CP(reg_A, reg_L); break;
		case 0xFE: CP(reg_A, value); opbytes = 2; break;
		case 0xBE: CP(reg_A, Pair(reg_H, reg_L).address()); break;
		case 0x3C: INC(reg_A); break;
		case 0x04: INC(reg_B); break;
		case 0x0C: INC(reg_C); break;
		case 0x14: INC(reg_D); break;
		case 0x1C: INC(reg_E); break;
		case 0x24: INC(reg_H); break;
		case 0x2C: INC(reg_L); break;
		case 0x34: INC(Pair(reg_H, reg_L).address()); break;
		case 0x3D: DEC(reg_A); break;
		case 0x05: DEC(reg_B); break;
		case 0x0D: DEC(reg_C); break;
		case 0x15: DEC(reg_D); break;
		case 0x1D: DEC(reg_E); break;
		case 0x25: DEC(reg_H); break;
		case 0x2D: DEC(reg_L); break;
		case 0x35: DEC(Pair(reg_H, reg_L).address()); break;
		// 97
		case 0x09: ADDHL(Pair(reg_B, reg_C)); break;
		case 0x19: ADDHL(Pair(reg_D, reg_E)); break;
		case 0x29: ADDHL(Pair(reg_H, reg_L)); break;
		case 0x39: ADDHL(Pair(reg_A, reg_F)); break;
		case 0xE8: ADDSP(value); opbytes = 2; break;
		case 0x03: INC(Pair(reg_B, reg_C)); break;
		case 0x13: INC(Pair(reg_D, reg_E)); break;
		case 0x23: INC(Pair(reg_H, reg_L)); break;
		case 0x33: INC(Pair(reg_A, reg_F)); break;
		case 0x0B: DEC(Pair(reg_B, reg_C)); break;
		case 0x1B: DEC(Pair(reg_D, reg_E)); break;
		case 0x2B: DEC(Pair(reg_H, reg_L)); break;
		case 0x3B: DEC(Pair(reg_A, reg_F)); break;
		// 98
		case 0x07: RL(reg_A, true); break; // manual shows the logic switched for these functions
		case 0x17: RL(reg_A, false); break; // implementation matches expected output for these two
		case 0x0F: RR(reg_A, false); break; // implementation matches expected output when these two instructions are switched
		case 0x1F: RR(reg_A, true); break;
		// 99 - 104
		case 0xCB: parse_bit_op(value); opbytes = 2; break;
		// 105
		case 0xC3: JP(Pair(value2, value)); opbytes = 3; break;

		case 0xC2: JPNZ(Pair(value2, value)); opbytes = 3; break;
		case 0xCA: JPZ(Pair(value2, value)); opbytes = 3; break;
		case 0xD2: JPNC(Pair(value2, value)); opbytes = 3; break;
		case 0xDA: JPC(Pair(value2, value)); opbytes = 3; break;

		case 0xE9: JPHL(); break;
	}

	return opbytes;
}



while (true)
{
	read the opcode...
	do what the opcode tells you to do...
	do the next opcode

	render the video
	play the audio
}