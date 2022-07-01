#ifndef CPU_HPP
#define CPU_HPP

#include <bits/stdc++.h>
#include "buffer_stages.hpp"
#include "global.hpp"

using u32 = unsigned int;
using u8  = unsigned char;

u32 all_empty_flag;

class cpu{
public:
cpu(){
    memset(mem,0,sizeof(mem));
    memset(reg,0,sizeof(reg));
    STAGE::STALL_post_D_F_W_bubble = 0;
    STAGE::discard_flag = 0;
    PC = 0;
    clk = 0;
    all_empty_flag = 1;
}

~cpu(){}

void init(std::istream &in){
    std::string s = "";
    u32 ptr = 0;
    in>>s;
    while(!in.fail() && s != "###"){
        if(s == "###")break;
        if(s[0] == '@'){
            char *tmp;
            ptr = strtoul(s.substr(1,8).c_str(),&tmp,16);
        } else {
            char *tmp;
            mem[ptr] = strtoul(s.c_str(),&tmp,16);//自然分界读写
            //printf("[%s,%d] \n", s.c_str(), mem[ptr]);
            ptr++;
        }
        in>>s;
    }
}

void set(){
	STAGE::IF_ID.obn = STAGE::ID_EX.obn = STAGE::EX_MEM.obn = STAGE::MEM_WB.obn = none;
    STAGE::res_IF_ID.obn = STAGE::res_ID_EX.obn = STAGE::res_EX_MEM.obn = STAGE::res_MEM_WB.obn = none;
}
void pipeRUN(){
    set();
    extern bool eesc;
	eesc = false;
    while(1){
        clk++;
        STAGE::ID();
        STAGE::MEM();
        STAGE::WB();
        //MEM/WB
        STAGE::EX();        
        STAGE::IF();
        STAGE::updateALL();
        if(eesc)break;
    }
}

};
#endif //CPP_HPP
