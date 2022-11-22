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
		ledOn(6);						// T�nd r�d LED
		system("cls");					// Slet sk�rmen
		printf_s("%s", "LOCKED\n\n");

		printf_s("%s", "Tast din kode for at l\x86se d\x9Bren op - eller tast + for at lukke systemet ned\n\n");

		// Vent s� l�nge der ikke trykkes p� PC tastatur og der ikke trykkes p� "udknap" (key P1 p� RP'en)
		while (!keyPressed(P1) && !_kbhit())
		{}

		// Der blev trykket p� PC tastaturet
		if (_kbhit())
		{
			// Indl�s karakteren og gem p� 1. plads i codeFromKeyboard[]
			// Hvis den indl�ste karakter IKKE er '+'
			// Indl�s de n�ste 7 karakterer - EN ad gangen og gem l�bende i codeFromKeyboard[]
			// HVER GANG der er indl�st en karakter udskrives en '*' p� sk�rmen
			// Gem til sidst '\0' p� sidste plads i codeFromKeyboard[]
			// Kald checkCode() og gem svar i variablen codeOkay
			// Hvis koden er forkert
			// Udskriv fejlmeddellelse og vent 5 sek

			fgets(codeFromKeyboard, CODE_SIZE + 1, stdin);

			if (!codeFromKeyboard[0] != '+')
			{
				 
			}
		}
		// Der blev trykket p� "udknap"
		else
			codeOkay = 1;

		// Den indtastede kode er korrekt eller der blev trykket p� "udknap"
		if (codeOkay == 1)
		{
			// Her skrives den del af programmet som l�ser "d�ren" op/l�ser "d�ren" og styrer LED'erne
			// NB! "D�ren skal automatisk l�ses igen efter 10 sekunder (se opgaveteksten)

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
