
//RB1�|�[�g�ɂ�L�`�J���s���v���O�����B
//�v���W�F�N�g���쐬����ہA���{��ŃR�����g���c������
//encoding��Shift_Jis�ɐݒ肷�邱�ƁB����ȊO���ƕ�����������B

// CONFIG
//�ȉ��̃R���t�B�O�̓\�[�X�t�@�C���쐬��A
//production �^�u��� set configuration bits��I���A
//generate source code to Output���玩�������������́B

#pragma config FOSC = INTOSCIO //����p�N���b�N�̑I���BINTOSCIO�œ����N���b�N���g�p�\
#pragma config WDTE = OFF      //�E�H�b�`�h�b�O�^�C�}�̎g�p�ہB��₱�����̂Ŏg��Ȃ��B 
#pragma config PWRTE = ON      //�d�������シ���ɂ͓d�������肵�Ȃ����ꂪ����̂ŏ����҂B���D�݂ŁB

#pragma config MCLRE = ON      //MCLR�s�����n�[�h�E�F�A���Z�b�g�Ƃ��Ďg�����ǂ����B
                               //ON�ɂ����ꍇ�AMCLR�s����GPIO�Ƃ��Ďg�p���邱�Ƃ͕s�\�ɂȂ�B
                               //���10k���قǂŃv���A�b�v���Ă����B0V�ɗ��Ƃ��ƁA���Z�b�g�����B

#pragma config BOREN = ON      //�d�����s����ɂȂ����ۃ��Z�b�g���邩�ǂ����B���D�݁B
#pragma config LVP = ON        //��d���ŏ������݂����B���ɂ͂���Ȃ��B
#pragma config CPD = OFF       //�R�[�h�̕ی�Ƃ�����Ȃ́B�����B 
#pragma config CP = OFF        //��Ɠ����悤�Ȃ́B�����


#include <xc.h>
#define _XTAL_FREQ 4000000 //�f�t�H���g�ł͎��g����4MHz


int main(void)
{
    
    CMCON = 0x07;       //�R���p���[�^�@�\�̐ݒ�B�s�g�p��0x07
    TRISA = 0b11000011; //���o�͂̐ݒ�B�|�[�g���B���bit����RA7->RA0�ɑΉ�
    TRISB = 0x00;       //����������o�́B0x00=0b00000000 0=�o�� 1=����
    while (1){
      //PORTB = 0b00000010;        //���̂悤�ɁA�S�̂��ꊇ�ŊǗ��\�B
        RB1 = 1;                   //��Ɠ������Ƃ����Ă���
        __delay_ms(200);           //�i���j�擪��__�́A�A���_�[�o�[2�B()���ɕϐ����������Ƃ͂ł��Ȃ��B
      //PORTB = 0b00000000;
        RB1 = 0;
        __delay_ms(200);
    }
	return 0;
}


//�������݂̍ۂɂ́A�v���W�F�N�g���E�N���b�N����v���p�e�B�A
//categories���pickit3��I�����AOption categories��Power�ɁA
//��Ƀ`�F�b�N�����A�d����5V������(����4.75�ŗ��p��)�ɂ��邱�ƁB

