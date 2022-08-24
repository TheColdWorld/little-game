#include "pch.h"
#include "little-game.server.class.h"
class player
{
public:
    //���캯��������Ϸ�ṩ��ʼ������
    player()
    {
        NAME = "player";
        MXHP =  HP = 1000;
        DMG1 = 20;
        DMG2 = 40;
        TOTALCOIN = COINS = MXMP = MP = 200;
        POT2HAS = POT1HAS = 2;
        GAPPLEHAS = 1;
        W31 = W22 = W21 = W12 = W11 = W02 = W01 = C12 = C11 = C10 = C09 = C08 = C07 = C06 = C05 = C04 = C03 = C02 = C01 = POT6 = POT5 = POT4 = POT3 = POT4HAS = POT3HAS = PROT = DMGE = POTIONS = 0;
        A242 = A241 = A23 = A22 = A21 = A17 = A16 = A15 = A142 = A141 = A13 = A12 = A11 = A07 = A06 = A05 = A042 = A041 = A03 = A02 = A01 = W42 = W41 = W32 = 0;
        E7 = E6 = E5 = E42 = E41 = E3 = E2 = E1 = A47 = A46 = A45 = A042 = A041 = A33 = A32 = A31 = A26 = A25 = 0;
    }
    double Gethp() { return HP; }
    double GetMaxhp() { return MXHP; }
    int Getmp() { return MP; }
    int GetMaxmp() { return MXMP; }
    double GetDmg1() { return DMG1; }
    double GetDmg2() { return DMG2; }
    double GetDmgE() { return DMGE; }
    int GetProt() { return PROT; }
    int GetCoins() { return COINS; }
    int GetTotalcoins() { return TOTALCOIN; }
    std::string Getname() { return NAME; }
    int Getpotions()
    {
        if (POTIONS == 0) return 0;
        else return POTIONS * 10000 + POT3 * 1000 + POT4 * 100 + POT5 * 10 + POT6;
    }
    int HavePoiton1() { return POT1HAS; }
    int HavePotion2() { return POT2HAS; }
    int HavePotion3() { return POT3HAS; }
    int HavePotion4() { return POT4HAS; }
    int HaveGapple() { return GAPPLEHAS; }
    long Getw1has()
    {
        return W01 + W02 * 10 + W11 * 100 + W12 * 1000 + W21 * 10000 + W22 * 100000 + W31 * 1000000 + W32 * 10000000 + W41 * 100000000 + W42 * 10000000000;
    }
    long Getc()
    {
        return C01 + C02 * 10 + C03 * 100 + C04 * 1000 + C05 * 10000 + C06 * 100000 + C07 * 1000000 + C08 * 10000000 + C09 * 100000000 + C10 * 1000000000 + C11 * 10000000000 + C12 * 100000000000;
    }
    int Geta0()
    {
        return A01 + A02 * 10 + A03 * 100 + A041 * 1000 + A042 * 10000 + A05 * 100000 + A06 * 1000000 + A07 * 10000000;
    }
    int Geta1()
    {
        return A11 + A12 * 10 + A13 * 100 + A141 * 1000 + A142 * 10000 + A15 * 100000 + A16 * 1000000 + A17 * 10000000;
    }
    int Geta2()
    {
        return A21 + A22 * 10 + A23 * 100 + A241 * 1000 + A242 * 10000 + A25 * 100000 + A26 * 1000000 + A27 * 10000000;
    }
    int Geta3()
    {
        return A31 + A32 * 10 + A33 * 100 + A341 * 1000 + A342 * 10000 + A35 * 100000 + A36 * 1000000 + A37 * 10000000;
    }
    int Geta4()
    {
        return A41 + A42 * 10 + A43 * 100 + A441 * 1000 + A442 * 10000 + A45 * 100000 + A46 * 1000000 + A47 * 10000000;
    }
    void Takedamege(double demage) { HP -= demage; }
    double Getdemage1() { return DMG1 + DMGE; }
    double Getdemage3() { return DMG2 + DMGE; }
    int DOit(int cho, double takedmg, double ipp, int prop)
    {
        ReloadEDMG();
        ReloadProt();
        prop = PROT;
        switch (cho)
        {

        default:
            break;
        }
    }
private:
    //��������
    int Getwear()
    {
        return E1 + E2 * 10 + E3 * 100 + E41 * 1000 + E42 * 10000 + E5 * 100000 + E6 * 1000000 + E7 * 10000000;
    }
    void ReloadProt()
    {
        PROT = 0;
        //װ������[1:Fe,2:Au,3:Fe-Au�Ͻ�,4:��ʯ(C),5.Fe-Au-C�Ͻ�]
        switch (E1)
        {
        case 1:
            PROT += 2;
            break;
        case 2:
            PROT += 1;
            break;
        case 3:
            PROT =+ 3;
            break;
        case 4:
            PROT += 5;
            break;
        case 5:
            PROT += 6;
            break;
        }
        switch (E2)
        {
        case 1:
            PROT += 4;
            break;
        case 2:
            PROT += 2;
            break;
        case 3:
            PROT = +5;
            break;
        case 4:
            PROT += 5;
            break;
        case 5:
            PROT += 10;
            break;
        }
        switch (E3)
        {
        case 1:
            PROT += 3;
            break;
        case 2:
            PROT++;
            break;
        case 3:
            PROT += 4;
            break;
        case 4:
            PROT += 6;
            break;
        case 5:
            PROT += 8;
        }
        switch (E41)
        {
        case 1:
            PROT++;
            break;
        case 2:
            PROT++;
            break;
        case 3:
            PROT++;
            break;
        case 4:
            PROT += 2;
            break;
        case 5:
            PROT += 3;
        }
        switch (E42)
        {
        case 1:
            PROT++;
            break;
        case 2:
            PROT++;
            break;
        case 3:
            PROT++;
            break;
        case 4:
            PROT += 2;
            break;
        case 5:
            PROT += 3;
        }
        switch (E5)
        {
        case 1:
            PROT++;
            break;
        case 2:
            PROT++;
            break;
        case 3:
            PROT++;
            break;
        case 4:
            PROT += 2;
            break;
        case 5:
            PROT += 2;
        }
        switch (E6)
        {
        case 1:
            PROT++;
            break;
        case 2:
            PROT++;
            break;
        case 3:
            PROT++;
            break;
        case 4:
            PROT += 2;
            break;
        case 5:
            PROT += 2;
        }
        if (E7 == 5) PROT++;
    }
    void ReloadEDMG()
    {
        DMGE = 0;
        switch (EW)
        {
        case 10:
            DMGE += 2;
            break;
        case 11:
            DMGE += 3; 
            break;
        case 20:
            DMGE ++;
            break;
        case 21:
            DMGE += 2;
            break;
        case 30:
            DMGE += 3;
            break;
        case 31:
            DMGE += 4;
            break;
        case 40:
                DMGE += 7;
                break;
        case 41:
            DMGE += 8;
            break;
        case 50:
            DMGE += 9;
            break;
        case 51:
            DMGE += 10;
            break;
        }
    }
    int DrinkPot1()
    {
        if (POT1HAS == 0) return -1;
        else
        {
            POT1HAS--;
            HP += 50;
            return 0;
        }
    }
    int DrinkPot2()
    {
        if (POT2HAS == 0) return -1;
        else
        {
            POT2HAS--;
            MP += 50;
            return 0;
        }
    }
    int DrinkPot3()
    {
        if (POT3HAS == 0) return -1;
        if (POT3 != 0)
        {
            POT3HAS--;
            POT3 = 3;
            return 1;
        }
        else
        {
            POT3HAS--;
            POTIONS++;
            POT3 += 3;
            return 0;
        }
    }
    int DrinkPot4()
    {
        if (POT4HAS == 0) return -1;
        if (POT4 != 0)
        {

            POT4HAS--;
            POT4 = 3;
            return 1;
        }
        else
        {
            POT4HAS--;
            POTIONS++;
            POT4 += 3;
            return 0;
        }
    }
    int EatGapple()
    {
        if (GAPPLEHAS == 0) return -1;
        if (POT3 != 0)
        {
            GAPPLEHAS--;
            HP += 25;
            POT3 = 2;
            return 1;
        }
        else
        {
            GAPPLEHAS--;
            POTIONS++;
            HP += 25;
            POT3 += 2;
            return 0;
        }

    }
    //��������
    double HP;//Ѫ��(����)
    double MXHP;//���Ѫ��(����)
    double DMG1;//�˺�1
    double DMG2;//�˺�2
    double DMGE;//���ӵ��˺�
    int MP;//����(����)
    int MXMP;//�������(����)
    int PROT;//����(����)
    int COINS;//Ŀǰ�����
    int TOTALCOIN;//��ý������(����)
    std::string NAME;//����(����)
    //ҩˮ����
    int POTIONS;//ӵ��ҩˮЧ������(����)
    int POT1HAS;//˲������
    int POT2HAS;//MP˲��ظ�
    int POT3HAS;//�����ָ�
    int POT4HAS;//MP�ָ�
    int GAPPLEHAS;//��ƻ��[��Ѫ+�����ָ�(2r)]
    int POT3;
    int POT4;
    int POT5;//�ж�[ÿ�ֵ�25Ѫ��][��������]
    int POT6;//����[ÿ�ֵ�50Ѫ��]
    //���ϱ���
    int C01;//ľ��
    int C02;//����
    int C03;//����ʯ
    int C04;//��ʯ
    int C05;//��
    int C06;//���ʯ
    int C07;//��עģ
    int C08;//��עģ
    int C09;//ƻ��
    int C10;//Ƥ��
    int C11;//���ϺϽ𶧣�2��2��2��ʯ->3����
    int C12;//�����Ͻ𶧣�2��2��->1����
    //��������[0:��,1:��,2:�����Ͻ�,3:��ʯ,4.���ϺϽ�]{1:��,2:��}
    int W01;//2
    int W02;//3
    int W11;//1
    int W12;//2
    int W21;//3
    int W22;//4
    int W31;//7
    int W32;//8
    int W41;//9
    int W42;//10
    //���ױ���[0:��,1:��,2:�����Ͻ�,3:��ʯ,4.���ϺϽ�]{1:ͷ��,2:�ؼ�,3:����,41:ѥ��(��),42:ѥ��(��),5:����(��),6:����(��),7:��Ʒ}
    int A01;//2
    int A02;//4
    int A03;//3
    int A041;//1
    int A042;//1
    int A05;//1
    int A06;//1
    int A07;//0
    int A11;//1
    int A12;//2
    int A13;//1
    int A141;//1
    int A142;//1
    int A15;//1
    int A16;//1
    int A17;//0
    int A21;//3
    int A22;//5
    int A23;//4
    int A241;//1
    int A242;//1
    int A25;//1
    int A26;//1
    int A27;//0
    int A31;//5
    int A32;//8
    int A33;//6
    int A341;//2
    int A342;//2
    int A35;//2
    int A36;//2
    int A37;//0
    int A41;//6
    int A42;//10
    int A43;//8
    int A441;//3
    int A442;//3
    int A45;//2
    int A46;//2
    int A47;//1
    //װ������[1:Fe,2:Au,3:Fe-Au�Ͻ�,4:��ʯ(C),5.Fe-Au-C�Ͻ�]{0:��,1:��}
    int E1;
    int E2;
    int E3;
    int E41;
    int E42;
    int E5;
    int E6;
    int E7;
    int EW;
};