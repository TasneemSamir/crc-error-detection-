#include <iostream>
//#include <cstring>
using namespace std;


char message[30];
char poly[10];
char crc_value[30];
int poly_length;
int message_length;
int  j;

void XOR() {
	for (j = 1; j < poly_length; j++) {
		if (crc_value[j] == poly[j]) {
			crc_value[j] = '0';
		}
		else {
			crc_value[j] = '1';
		}
	}
}

void crc() {

	for (int i = 0; i < poly_length; i++) {
		crc_value[i] = message[i];
	}

	int i = poly_length;
	do {

		if (crc_value[0] == '1')
			XOR();


		for (j = 0; j < poly_length - 1; j++) {
			crc_value[j] = crc_value[j + 1];

		}
		crc_value[j] = message[i++];

	} while (i <= message_length + (poly_length - 1));

}

	
void recevier() {
	cout << endl << " enter recevied data :";
	cin >> message;
	crc();
	int flag = 0;

	for (int i = 0; i < poly_length - 1; i++)
	{
		if (crc_value[i] == '1') {
			flag = 1;
			cout << "error detected ";
			break;
		}
	}

	if (flag == 0) 
		cout << "no error detected ";

}

int main() {
	cout << " enter the data to be transmitted :" << endl;
	cin >> message;

	cout << " enter the generating polynomial : " << endl;
	cin >> poly;

	poly_length = strlen(poly);
	message_length = strlen(message);

	for (int i = message_length; i < message_length + (poly_length - 1); i++)
	{
		message[i] = '0';
	}

	crc();
	cout << " CRC : " << crc_value;

	recevier();

} 


