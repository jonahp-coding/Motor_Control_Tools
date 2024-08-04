uint8_t target_speed = 150; // { adjust this value as you please... }
uint16_t rate = 5000; // how long motor should take to reach 'R_target_speed' { adjust this value as you please... }
uint8_t speed; // instantaneous speed of motor
uint16_t acceleration_timestamp; // instantaneous timestamp of motor acceleration
uint16_t initial_timestamp; // timestamp at beginning of motor acceleration
uint8_t initial_speed = 50; // the intial speed of motor at beginning of acceleration { adjust this value as you please... }

motor_set_pwm(initial_speed);
current_millis = millis();
initial_timestamp = current_millis;

while (current_millis - initial_timestamp < rate) {
  current_millis = millis();
  speed = map(current_millis, initial_timestamp, (initial_timestamp + rate), initial_speed, target_speed);
  acceleration_timestamp = current_millis - initial_timestamp;

  motor_set_pwm(speed);

  Serial.print("speed: ");
  Serial.println(speed);
  Serial.print("acceleration_timestamp(ms): ");
  Serial.println(acceleration_timestamp);
  Serial.println("-----------------------------");
}
