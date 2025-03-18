import serial
form influxdb_client import influxDBCclient
import time

serial_port = 'COM2'
baud_rate = 9600
timeout = 2

# InfluxDB  v2 설정
client = InfluxDBClient(url=influxdb_url, token=influxdb_token, org=influxdb_org)
write_api = client.write_api()


# 시리얼 포트 열기
try:
	ser = serial.Serial(serial_port, baudrate, timeout=timeout)
	print(f"Connectde to {serial_port} at {baudrate} baud")
except serial.SerialException:
	print("Failed to connect to serial port.")
	exit()
try:
	while True:
		if ser.in_waiting > 0:
			# 아두이노로부터 시리얼 데이터를 읽음
			line = ser.readline().decode('UTF-8').strip() 
			# 데이터가 유호한 경우 influxDB에 기록
			print(f"Received: {line}")

			if "=" in line:
				key, value = line.split("=")
				try:
					value = float(value) 
					data = f"sensor_data,device=arduino {key}={value}"
					write_api.write(bucket=influxdb_bucket,record=data)
					print(f"Data written to InfluxDB: {key}={value}")
				except ValueError:
					print("Invalid data format")
		time.sleep(1) 
except KeyboardInterrupt:
	print("프로그램이 종료되었습니다")

finally:
	ser.close()