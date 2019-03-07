
//RB1ポートにてLチカを行うプログラム。
//プロジェクトを作成する際、日本語でコメントを残すため
//encodingはShift_Jisに設定すること。これ以外だと文字化けする。

// CONFIG
//以下のコンフィグはソースファイル作成後、
//production タブより set configuration bitsを選択、
//generate source code to Outputから自動生成したもの。

#pragma config FOSC = INTOSCIO //動作用クロックの選択。INTOSCIOで内部クロックを使用可能
#pragma config WDTE = OFF      //ウォッチドッグタイマの使用可否。ややこしいので使わない。 
#pragma config PWRTE = ON      //電源投入後すぐには電圧が安定しない恐れがあるので少し待つ。お好みで。

#pragma config MCLRE = ON      //MCLRピンをハードウェアリセットとして使うかどうか。
                               //ONにした場合、MCLRピンをGPIOとして使用することは不可能になる。
                               //常に10kΩほどでプルアップしておく。0Vに落とすと、リセットされる。

#pragma config BOREN = ON      //電圧が不安定になった際リセットするかどうか。お好み。
#pragma config LVP = ON        //低電圧で書き込みするやつ。自分にはいらない。
#pragma config CPD = OFF       //コードの保護とかそんなの。しらん。 
#pragma config CP = OFF        //上と同じようなの。いらね


#include <xc.h>
#define _XTAL_FREQ 4000000 //648aの場合、デフォルトでは周波数が4MHz


int main(void)
{
    
    CMCON = 0x07;       //コンパレータ機能の設定。不使用は0x07
    TRISA = 0b11000011; //入出力の設定。ポート毎。上位bitからRA7->RA0に対応
    TRISB = 0x00;       //こちらも入出力。RB7->RB0 0x00=0b00000000 0=出力 1=入力
    while (1){
      //PORTB = 0b00000010;        //このように、全体を一括で管理可能。それぞれのピンのON/OFFを切り替える。
        RB1 = 1;                   //上と同じことをしている
        __delay_ms(200);           //（注）先頭の__は、アンダーバー2つ。()内に変数を使うことはできない。
      //PORTB = 0b00000000;
        RB1 = 0;
        __delay_ms(200);
    }
	return 0;
}


//書き込みの際には、プロジェクト名右クリックからプロパティ、
//categoriesよりpickit3を選択し、Option categoriesをPowerに、
//上にチェックを入れ、電圧を5Vあたり(自分は4.75で利用中)にすること。

