#define REFRESH 20 //设置REFRESH表示20
int TrigPin=51;  //声明整型变量TrigPin为51  超声波控制信号输出
int EchoPin=49;  //声明整型变量EchoPin为49 超声波信号输入
int PowerPin=53; //声明整型变量PowerPin为53
int GroundPin=47; //声明整型变量GroundPin为49
long time，temp; //声明长整型变量time(存储8个脉冲时间)，temp室内温度
double distance; //声明双精度浮点变量，存储距离数据

void setup(){
  pinMode(PowerPin,OUTPUT); //设置PowerPin为输出模式，用来给超声波模块提供VCC，作为电源＋
  pinMode(GroundPin,OUTPUT); //设置GroundPin为输出模式，用来超声波模块提供GND，作为电源－
  digitalWrite(PowerPin,HIGH); //初始化PowerPin，使得电压为5V，作为电源+
  digitalWrite(GroundPin,LOW); //初始化GroundPin，使得电压为0V，作为电源-
  pinMode(TrigPin,OUTPUT);  //设置TrigPin为输出模式，用来触发模块发射超声波
  pinMode(EchoPin,INPUT);  //设置EchoPin为输入模式，用来接受脉冲时长
  temp=20; //初始化室内温度为20摄氏度
  Serial.begin(9600); //初始化串口输出，波特率为9600
}
void loop(){
  digitalWrite(TrigPin,HIGH); //设置TrigPin为高电平
  delayMicroseconds(50); //等待50us
  digitalWrite(TrigPin,LOW); //设置TrigPin为低电平，以上3步在TrigPin上输出50us的脉冲，触发模块工作
  time=pulseIn(EchoPin,HIGH,10000); //在EchoPin上等待高电平脉冲，超过10ms没有收到就继续运行，收到就返回脉冲长度并赋值给time
  distance=(331.3+(0.606*temp))*(time)/20000; //通过time和temp计算距离，注意8个脉冲，超声波来回
  Serial.print(distance); //通过串口输出距离
  Serial.println(); //通过串口输出换行符
  delay(REFRESH); //等待REFRESH时间后继续运行loop()
  }
