// Ardumower mower motor controller

#ifndef MOTORMOW_H
#define MOTORMOW_H




class MotorMowControl
{
  public:
    float motorPWMCurr;         // current PWM
    float motorMowAccel      ;  // motor mower acceleration (warning: do not set too high)
    float motorMowSpeedMaxPwm;    // motor mower max PWM
    float motorMowPowerMax;     // motor mower max power (Watt)
    float motorSenseScale;   // motor mower sense scale  (mA=(ADC-zero) * scale)

    float motorSenseCurrent;  // current motor current (mA)
    float motorSensePower;    // current motor power (W)

    bool motorError;            // motor error?
    bool motorStalled;          // motor stalled?
    bool enableErrorDetection;  // enable error detection?
    bool enableStallDetection;  // enable stall detection?

    MotorMowControl();
    virtual void setup();
    virtual void run();
    bool hasStopped();
    void setState(bool state);
    void resetStalled();
    void resetFault();
    void stopImmediately();
    void print();
  private:
    virtual void setSpeedPWM(int pwm);
    unsigned long lastMotorCurrentTime;
    void checkMotorFault();
    virtual void readCurrent();
    unsigned long nextMotorMowTime;
    // --- driver ---
    virtual int driverReadCurrentADC();
    virtual bool driverReadFault();
    virtual void driverSetPWM(int pwm);
    virtual void driverResetFault();
};



#endif

