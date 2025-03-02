
unsigned int GPIOA_BASE_=0x50000000UL, GPIO_ODR_OFFSET_=0x14;
#define GPIOA_ODR (*((volatile unsigned int *)(GPIOA_BASE_ + GPIO_ODR_OFFSET_)))

int _start();
int main(){
    int a = 10;
    a += a;
    a -= a;
    (*((volatile unsigned int *)(0x50000028))) = 0x0;
    return 0;
}