#include <stdio.h>
/**
功能：从键盘读入某宿舍6楼住户某月的水、电用量及水费、电费标准，请计算个住户应交水费、电费，并合计

地址   水（吨） 电（度）
101    5      150
102    4      90
103    4      120
104    3      78
105    5      60

水费：1.5元/吨  电费0.8元/度


思路：

用一个array_info[5][3]数组来存储各住户的相关信息：地址、用水量、用电量
用water_price、electric_price 来存储水费和电费的单价

**/

int main(){
    int array_info[5][3];//用来存储住户信息
    double water_price,electric_price;//存储水费和电费的单价
    double water_fee_sum=0.0,electric_fee_sum=0.0;//用来存储所有该层住户水费和电费的合计

    printf("Please input water and electric price：");
    scanf("%lf%lf",&water_price,&electric_price);
    printf("%.3lf %.3lf\n",water_price,electric_price);

    printf("Please input household information:\n");
    for(int i=0; i < 5 ;i++){
        for(int j=0; j < 3 ; j++){
            scanf("%d",&array_info[i][j]);
        }
    }
    printf("Result:\nID,water,electric,water_fee,electric_fee:\n");
    for(int i=0; i <  5 ;i++){
        for(int j=0;j < 3 ; j++){
           printf("%d ",array_info[i][j]);
        }
        double water_fee,electric_fee;
        water_fee = water_price * array_info[i][1];//求算水费
        electric_fee = electric_price * array_info[i][2];//求算电费
        water_fee_sum += water_fee;//该层住户累计水费
        electric_fee_sum += electric_fee;//该层住户累计电费
        printf("%.3lf %.3lf",water_fee,electric_fee);
        printf("\n");
    }
    printf("water_fee_sum is :%.3lf,electric_fee_sum is :%.3lf",water_fee_sum, electric_fee_sum);
    return 0;
}
