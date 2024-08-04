void accelerate_motor(uint8_t target_speed_param, uint16_t rate_param, uint8_t initial_speed_param) {
  uint8_t target_speed = target_speed_param; // { adjust this value as you please... }
  uint8_t initial_speed = initial_speed_param; // the intial 'pwm' speed of motor at beginning of acceleration { adjust this value as you please... }
  uint16_t rate = rate_param; // how long motor should take to reach 'R_target_speed' in 'ms' { adjust this value as you please... }
  uint16_t current_millis = millis();
  
  uint8_t speed; // instantaneous speed of motor
  uint16_t acceleration_timestamp; // instantaneous timestamp of motor acceleration
  uint16_t initial_timestamp; // timestamp at beginning of motor acceleration
  
  motor_set_pwm(initial_speed);
  current_millis = millis();
  initial_timestamp = current_millis;
  
  while (current_millis - initial_timestamp < rate) {
    current_millis = millis();
    speed = map(current_millis, initial_timestamp, (initial_timestamp + rate), initial_speed, target_speed);
    acceleration_timestamp = current_millis - initial_timestamp;
  
    motor_set_pwm(pin, speed);
  
    Serial.print("speed(pwm): ");
    Serial.println(speed);
    Serial.print("acceleration_timestamp(ms): ");
    Serial.println(acceleration_timestamp);
    Serial.println("-----------------------------");
  }
}

void motor_set_pwm(uint8_t motor_pin, uint8_t pwm_val) {
  analogWrite(motor_pin, pwm_val);
}
