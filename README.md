# RISC-V-simulator

## 五级流水

- 自测样例已通过
- OJ已通过
- 乱序自测已完成
- 乱序OJ测试已完成

## 文件结构
### RISCV.cpp
- I/O
### global.hpp 
- 全局变量:PC,mem,reg,clk,eesc
- enum类型: OPflag , object_num
- print函数 
- buffer定义

### my_cpu.hpp
- cpu类

### stages.hpp
- five stages
- forwarding
- stall the pipeline when predict wrong

### predictor.hpp
1. predictor:

    1. 两位饱和计数器预测:
        - 一级预测
        - 二级自适应预测

| 数据点 | 成功率 | 预测成功次数 | 预测总次数 |
| :----: | :----: | :----: | :----: |
|array_test1|50.00%|11|22|
|array_test2|46.15%|12|26|
|basicopt1|99.22%|153926|155139|
|bulgarian|94.64%|67659|71493|
|expr|81.98%|91|111|
|gcd|63.33%|76|120|
|hanoi|99.05%|17291|17457|
|lvalue2|66.67%|4|6|
|magic|85.14%|57785|67869|
|manyarguments|80.00%|8|10|
|multiarray|54.94%|89|162|
|naive|无|0|0|
|pi|84.45%|33742485|39956380|
|qsort|96.76%|193572|200045|
|queens|81.06%|62508|77116|
|statement_test|62.87%|127|202|
|superloop|99.25%|431781|435027|
|tak|80.53%|48832|60639|
