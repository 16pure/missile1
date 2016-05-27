#include <stdio.h>
#include <math.h>

struct robo {
        double x;
        double y;
        double dx;
        double dy;
        double v;
        double dv;
        double vx;
        double vy;
        double dvx;
        double dvy;
        double th;
        double th0;
        double dth;
        double w;
        double dw;
        double t;
        double r;
	double r0;
        double dr;
        double pi;
	double xr;
	double yr;

};


main()
{
    short i,j,u,a;
    double pi = 3.14159265358979323846;

    struct robo dr[2];
    u=0;

    for(j=0;j<=2;j++){
    dr[j].x = 0.0;      //位置ｘの初期化
    dr[j].y = 0.0;      //位置ｙの初期値
    dr[j].t = 0.01;     //計算間隔
    dr[j].th = 0.0;     //角度の初期値
    dr[j].v = 5.0;      //速度の初期値
    dr[j].w = pi / 2.0; //角速度の初期値

    dr[j].dv = dr[j].v;
    dr[j].dvx = dr[j].vx;
    dr[j].dvy = dr[j].vy;    
    dr[j].dw = dr[j].w;
    dr[j].th=dr[j].th0;
}
    dr[1].x=1000.0;
    dr[1].y=1000.0;
    dr[1].v=-400.0;
    j=0;
    a=1;

    for (i = 0; i < 500; i++) {

        printf("%f %f %f %f\n", dr[j].x, dr[j].y,dr[j+1].x, dr[j+1].y);      //0 ｘ，ｙを表示する
        dr[j].v = 300.0;                      //1 速度ｖの計算
        dr[j].w = pi / 2.0;                 //2 角速度ｗの計算       
	dr[j].th = dr[j].th + (dr[j].w + dr[j].dw) * dr[j].t / 2.0; //3 角度を積分で求める
        dr[j].vx = dr[j].v * cos(dr[j].th);             //4 速度のｘ成分計算
        dr[j].vy = dr[j].v * sin(dr[j].th);             //4 速度のｙ成分計算
        dr[j].x = dr[j].x + (dr[j].vx + dr[j].dvx) * dr[j].t / 2.0; //5 位置ｘを積分で求める
        dr[j].y = dr[j].y + (dr[j].vy + dr[j].dvy) * dr[j].t / 2.0; //5 位置ｙを積分で求める

        dr[j].dv = dr[j].v;                       //6 計算結果を記憶する
        dr[j].dvx = dr[j].vx;
        dr[j].dvy = dr[j].vy;
        dr[j].dw = dr[j].w;

	j=1;
	
	dr[j].r=atan2((dr[j].y-dr[j-1].y),(dr[j].x-dr[j-1].x));
	
	if(u=1){
		dr[j].dr=(dr[j].r-dr[j].r0)/dr[j].t;
	u=1;
	}
	dr[j].w=8*dr[j].dr;
	
	dr[j].r0=dr[j].r;


        dr[j].th = dr[j].th + (dr[j].w + dr[j].dw) * dr[j].t / 2.0; //3 角度を積分で求める
	dr[j].vx = dr[j].v *cos(dr[j].th);             //4 速度のｘ成分計算
        dr[j].vy = dr[j].v * sin(dr[j].th);             //4 速度のｙ成分計算
        dr[j].x = dr[j].x + (dr[j].vx + dr[j].dvx) * dr[j].t / 2.0; //5 位置ｘを
        dr[j].y = dr[j].y + (dr[j].vy + dr[j].dvy) * dr[j].t / 2.0; //5 位置ｙを

        dr[j].dv = dr[j].v;                       //6 計算結果を記憶する
        dr[j].dvx = dr[j].vx;
        dr[j].dvy = dr[j].vy;
        dr[j].dw = dr[j].w;
	dr[j].vx = dr[j].v * cos(dr[j].th);             //4 速度のｘ成分計算
        dr[j].vy = dr[j].v * sin(dr[j].th);             //4 速度のｙ成分計算
        dr[j].x = dr[j].x + (dr[j].vx + dr[j].dvx) * dr[j].t / 2.0; //5 位置ｘを積分で求める
        dr[j].y = dr[j].y + (dr[j].vy + dr[j].dvy) * dr[j].t / 2.0; //5 位置ｙを積分で求める

        dr[j].dv = dr[j].v;                       //6 計算結果を記憶する
        dr[j].dvx = dr[j].vx;
        dr[j].dvy = dr[j].vy;
        dr[j].dw = dr[j].w;

	j=0;
	a=1;
	dr[0].xr=dr[1].x-dr[0].x;

	dr[0].yr=dr[1].y-dr[0].y;

	if(sqrt(dr[0].xr*dr[0].xr+dr[0].yr*dr[0].yr)<10)break;
//	if(dr[0].xr<10&&dr[0].xr>-10){
//		if(dr[0].yr<10&&dr[0].yr>-10)break;
//    }
}
}

