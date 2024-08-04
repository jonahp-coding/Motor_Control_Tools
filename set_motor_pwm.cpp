void motor_set_pwm(uint8_t motor_pin, uint8_t pwm_val) {
  analogWrite(motor_pin, pwm_val);
}
