uint8_t R_target_speed = motor_speed; // 'motor_speed'
uint16_t R_rate = 5000; // how long motor 'R' should take to reach 'R_target_speed'
uint8_t R_speed; // instantaneous speed of motor 'R'
uint16_t R_acceleration_timestamp; // instantaneous timestamp of motor 'R' acceleration
uint16_t R_initial_timestamp; // timestamp at beginning of motor 'R' acceleration
uint8_t R_initial_speed = 50; // the intial speed of motor 'L' at beginning of acceleration

void acceleration_test(uint16_t rate) {
  motor_1_set_pwm(R_initial_speed);
  current_millis = millis();
  R_initial_timestamp = current_millis;

  while (current_millis - R_initial_timestamp < rate) {
    current_millis = millis();
    R_speed = map(current_millis, R_initial_timestamp, (R_initial_timestamp + rate), R_initial_speed, R_target_speed);
    R_acceleration_timestamp = current_millis - R_initial_timestamp;

    motor_1_set_pwm(R_speed);

    Serial.print("R_speed: ");
    Serial.println(R_speed);
    Serial.print("R_acceleration_timestamp(ms): ");
    Serial.println(R_acceleration_timestamp);
    Serial.println("-----------------------------");
  }
}
