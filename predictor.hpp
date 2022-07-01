#ifndef PREDICTOR_HPP
#define PREDICTOR_HPP
#include <cstring>
#include <iostream>
using u32 = unsigned int;
using u8  = unsigned char;

//#define BHT_VALUE (BHT[iniPC & 0b111111111f])
#define BTB_VALUE (BTB[iniPC & 0b111111111])
#define OPcode (code & 0b1111111)

#define BHT_VALUE (BHT[iniPC & 0b111111111])
#define PHT_VALUE (PHT[iniPC & 0b111111111][BHT_VALUE]) 
extern double rate;
class predictor{
    u32 suc,cnt;
    u8 BHT[512];
    u8 PHT[512][64];
    u32 BTB[512];

public:
    predictor(){
        suc = 0;cnt = 0;
        memset(BHT,0,sizeof(BHT));
        memset(PHT,0,sizeof(PHT));
        memset(BTB,0,sizeof(BTB));
    }

    ~predictor(){
        //if(cnt == 0)printf("no Branch");
        //else printf("%lf ",((double) (suc)/cnt))
        //,rate += (double)suc / (double)cnt;
        //printf("suc : %d cnt %d \n\n",suc,cnt);
    }

    int predict(u32 code,u32 iniPC){
        if(OPcode == 0b1100011 && (PHT_VALUE & 0b10))return BTB_VALUE;
        return iniPC + 4;
    }//区分 0x and 0b !!!!!!
    void update(bool BranchTaken,bool isSuc,u32 iniPC,u32 jumpAddr){//针对分支命令分支是否被采纳
        if(isSuc)++suc;
        ++cnt;
        if(BranchTaken){
            if(PHT_VALUE < 0b11u)++PHT_VALUE;
            BHT_VALUE = (BHT_VALUE >> 1);
            BTB_VALUE = jumpAddr;
        } else {
            if(PHT_VALUE > 0b00u)--PHT_VALUE;
            BHT_VALUE = (BHT_VALUE >> 1) | 0b100000;
        }
    }
};

/* 二位饱和计数器预测
//only for b
class predictor{
    u32 suc,cnt;
    u8  BHT[4097];  //branch history table
    u32 BTB[65];    //branch target buffer
public:
    predictor(){
        suc = 0;cnt = 0;
        memset(BHT,0,sizeof(BHT));
        memset(BTB,0,sizeof(BTB));
    }
    
    ~predictor(){
    	if(cnt == 0)printf("no Branch");
        else printf("%lf\n",((double) (suc)/cnt));
    }

    int predict(u32 code,u32 iniPC){//都进
        if(OPcode == 0b1100011 && (BHT_VALUE & 0b10))return BTB_VALUE;
        return iniPC + 4;
    }

    //只有分支指令才调用此函数
    void update(bool BranchTaken,bool isSuc,u32 iniPC,u32 jumpAddr){//针对分支命令分支是否被采纳
        if(isSuc)++suc;
        //printf("%d\n",isSuc);
        ++cnt;
        //不管是否成功，用isBrT和jumpAddr来更新 
        //iniPC
        if(BranchTaken){
            if(BHT_VALUE < 0b11)++BHT_VALUE;
            BTB_VALUE = jumpAddr;
        } else {
            if(BHT_VALUE > 0b00)--BHT_VALUE;
        }
    }
};
*/


#endif