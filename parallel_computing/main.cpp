#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"

#include <iostream>
#include <omp.h>
#include <ctime>
#include <random>

using namespace std;


double area[8];

double f1(double x) {
    return 4*(1/(1+x*x));
}

bool insideCircle(double x, double y, double r){
    return ((x*x)+(y*y)) <= (r*r);
}

double calculate(int it, int r){
    double piResult = 0;
    int squareQuantity = 0;
    int circleQuantity = 0;

    std::random_device rd;
    std:mt19937 mt(rd());
    std::uniform_real_distribution<double> distance(-r, r);

    for (auto i=0; i<it; ++i){
        ++squareQuantity;
        circleQuantity += insideCircle(distance(mt), distance(mt), r) ? 1 : 0;
    }

    piResult = ((4*(double)circleQuantity) / squareQuantity);

    return piResult;
}

double calculate2(int it, int r){
    int squareQuantity = 0;
    int circleQuantity = 0;

    std::random_device rd;
    std:mt19937 mt(rd());
    std::uniform_real_distribution<double> distance(-r, r);

#pragma omp parallel for reduction (+ : circleQuantity, squareQuantity)
    for(int i=0; i<it; ++i){
        squareQuantity += 1;
        circleQuantity += insideCircle(distance(mt), distance(mt), r) ? 1 : 0;
    }

    return ((4*(double)circleQuantity)/squareQuantity);
}


int main(void){
    //
    // FIRST PART
    //
    double sum=0;
    double a=0;
    double b=1;
    double dx=0.0000000001;

    int start_time1=clock();

    for(double i=a; i<b; i+=dx) {
        sum += f1(i) * dx;
    }

    int stop_time1 = clock();

    cout << "1) Sum equals: " << sum << endl;
    cout << "1) Calculation time: " << (stop_time1 - start_time1)/(CLOCKS_PER_SEC) << " seconds\n\n" << endl;

    //
    // SECOND PART
    //
    double sum2=0;
    double start_time2 = omp_get_wtime();

#pragma omp parallel
    {
        int threadsNum = omp_get_num_threads();
        int currentThread = omp_get_thread_num();
        double omp_sum2 = 0;

        for(double i=a+(currentThread-1)*dx; i<b; i+=threadsNum*dx){
            omp_sum2 += f1(i) * dx;
        }

        area[currentThread] = omp_sum2;
    }

    double time2 = omp_get_wtime() - start_time2;

    for(int i=0; i<8; i++){
        sum2 += area[i];
    }

    cout << "2) Sum equals: " << sum2 << endl;
    cout << "2) Calculation time: " << time2 << " seconds\n\n" << endl;

    //
    // THIRD PART
    //
    double sum3=0;
    int threadsNum = omp_get_num_threads();
    int pts = (b-a)/dx;
    double start_time3 = omp_get_wtime();

#pragma omp parallel for reduction(+ : sum3)
    for(long i=1; i<pts; i+=threadsNum){
        sum3 += f1(a+dx*i)*dx;
    }

    double time3 = omp_get_wtime() - start_time3;

    cout << "3) Sum equals: " << sum3 << endl;
    cout << "3) Calculation time: " << time3  << " seconds\n\n" << endl;

    //
    // FOURTH PART
    //
    double start_time4 = omp_get_wtime();
    cout << "4) Sum equals: " << calculate(100000000, 1) << endl;
    double time4 = omp_get_wtime() - start_time4;
    cout << "4) Calculation time: " << time4 << " seconds\n\n" << endl;

    //
    // FIFTH PART
    //
    double start_time5 = omp_get_wtime();
    cout << "5) Sum equals: " << calculate2(100000000, 1) << endl;
    double time5 = omp_get_wtime() - start_time5;
    cout << "5) Calculation time: " << time5 << " seconds" << endl;

    return 0;

}
