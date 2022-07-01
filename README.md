# RISCV_pipeline

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
|array_test1|50.00%|suc : 11|cnt 22|
|array_test2|46.15%|suc : 12|cnt 26|
|basicopt1|99.22%|suc : 153926|cnt 155139|
|bulgarian|94.64%|suc : 67659|cnt 71493|
|expr|81.98%|suc : 91|cnt 111|
|gcd|63.33%|suc : 76|cnt 120|
|hanoi|99.05%|suc : 17291|cnt 17457|
|lvalue2|66.67%|suc : 4|cnt 6|
|magic|85.14%|suc : 57785|cnt 67869|
|manyarguments|80.00%|suc : 8|cnt 10|
|multiarray|54.94%|suc : 89|cnt 162|
|naive|\\|suc : 0|cnt 0|
|pi|84.45%|suc : 33742485|cnt 39956380|
|qsort|96.76%|suc : 193572|cnt 200045|
|queens|81.06%|suc : 62508|cnt 77116|
|statement_test|62.87%|suc : 127|cnt 202|
|superloop|99.25%|suc : 431781|cnt 435027|
|tak|80.53%|suc : 48832|cnt 60639|