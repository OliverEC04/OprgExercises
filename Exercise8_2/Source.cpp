#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <RaspberryDLL.h>
#include <Windows.h>
#include <conio.h>
#include "codeFunctions.h"

int main()
{
	if (!Open())
	{
		printf_s("Error with connection\n");
		exit(1);
	}

	printf_s("Connected to Raspberry Pi\n");

	char userCode[CODE_SIZE + 1], codeFromKeyboard[CODE_SIZE + 1];
	int codeOkay;

	createCode(userCode);

	printf_s("\nDin kode er %s\n\nTryk en tast for at aktivere systemet\n", userCode);

	getch();

	do
	{
		codeOkay = 0;					// Reset codeOkay
		ledOn(6);						// Tænd rød LED
		system("cls");					// Slet skærmen
		printf_s("%s", "LOCKED\n\n");

		printf_s("%s", "Tast din kode for at l\x86se d\x9Bren op - eller tast + for at lukke systemet ned\n\n");

		// Vent så længe der ikke trykkes på PC tastatur og der ikke trykkes på "udknap" (key P1 på RP'en)
		while (!keyPressed(P1) && !_kbhit())
		{}

		// Der blev trykket på PC tastaturet
		if (_kbhit())
		{
			// Indlæs karakteren og gem på 1. plads i codeFromKeyboard[]
			// Hvis den indlæste karakter IKKE er '+'
			// Indlæs de næste 7 karakterer - EN ad gangen og gem løbende i codeFromKeyboard[]
			// HVER GANG der er indlæst en karakter udskrives en '*' på skærmen
			// Gem til sidst '\0' på sidste plads i codeFromKeyboard[]
			// Kald checkCode() og gem svar i variablen codeOkay
			// Hvis koden er forkert
			// Udskriv fejlmeddellelse og vent 5 sek

			fgets(codeFromKeyboard, CODE_SIZE + 1, stdin);

			if (!codeFromKeyboard[0] != '+')
			{
				 
			}
		}
		// Der blev trykket på "udknap"
		else
			codeOkay = 1;

		// Den indtastede kode er korrekt eller der blev trykket på "udknap"
		if (codeOkay == 1)
		{
			// Her skrives den del af programmet som låser "døren" op/låser "døren" og styrer LED'erne
			// NB! "Døren skal automatisk låses igen efter 10 sekunder (se opgaveteksten)

			ledOff(6);
			ledOn(5);

			for (int i = 0; i < 10; i++)
			{
				Wait(1000);

				if (i % 2 == 0)
				{
					ledOff(5);
				}
				else
				{
					ledOn(5);
				}
			}

			codeOkay = 0;
		}
		if (codeOkay == 0)
		{
			ledOff(5);
			ledOn(6);
		}

	} while (codeFromKeyboard[0] != '+');

	ledOff(6);

	return 0;
}
