# Micro V1

## a)

Bringen Sie die Led3 auf dem Keyestudio Multi Purpose Board bzw. in der
Simulation mit 0,5 Hz zum Blinken. Dabei soll die LED 75% der Zeit an und
ansonsten aus sein. Hierzu können Sie das Beispiel aus der Vorlesung abwandeln.
Eine Anleitung zum Umgang mit MPLAB-X oder Microchip-Studio und Simul-IDE
finden Sie in „INGIM_prakt_einführung.pdf“.

## b)

Wandeln Sie das Programm so ab, dass Led3 und Led4 im Wechsel blinken. Damit
ist gemeint, dass die eine LED an und gleichzeitig die andere aus ist, und
umgekehrt. Es muss immer eine der beiden LEDs an sein. Die Frequenz des
Blinkens soll gegenüber V1a vervierfacht werden, beide LEDs sollen gleich lange
an sein.

## c)

Ergänzen Sie das vorige Programm: Nutzen Sie den Schalter SW1 und SW2 (ohne
Entprellung), um die RGB-GRÜN-LED ein- und auszuschalten. Mit einem
Tastendruck (nicht erst beim Loslassen) von SW2 soll die LED eingeschaltet, mit
einem Tastendruck von SW1 ausgeschaltet werden. Fragen Sie hierzu
kontinuierlich den Zustand der beiden Taster in der Endlosschleife des
Hauptprogramms ab. Folgende Routine kann hierzu als Basis (also mit
Ergänzungen) genutzt werden:

```
// Port configuration
// ...
char oldStatusPinD3 = 1;
char newStatusPinD3 = 1;

while (1){
// Edge Detection for PD
newStatusPinD3 = (PIND & (1 << PIND3));
if((!newStatusPinD3) && (oldStatusPinD3)){
// Action to be done
// ...
}
oldStatusPinD3 = newStatusPinD3;
...
...
}
```

## d)

Ergänzen Sie das vorige Programm: Durch einen Tastendruck auf SW1 soll
zusätzlich die RGB-BLAU-LED aktiviert werden, durch einen Tastendruck auf SW
soll diese ausgeschaltet werden. Allerdings sollen Sie jetzt hierzu die Interrupts
INTx nutzen, ohne den Taster zu entprellen! Der Taster soll also für die RGB-BLAU-LED nicht in der Endlosschleife „gepollt“ werden. Hierzu können Sie die Information
aus Abschnitt 2) sowie die Antworten zu F1.8 bis F1.12 nutzen.

## e) Optional

Zählen Sie in den ISRs mit, wie oft diese ausgeführt wurden. Stellen Sie
den Wert der beiden Zähler in der Endlosschleife von main() auf dem LCD dar.
Laden Sie hierzu die .h und .c Dateien für das LCD aus dem LCD-Ordner in OLAT
herunter, binden Sie diese in das Projekt ein (siehe Einführung zum INGIM
Praktikum). Inkludieren Sie die .h-Dateien (und zwar nur die .h Datei!) wie in
Abschnitt E1.3 beschrieben. Sie können mit Hilfe der sprintf()-Funktion eine Integer-
Variable in einen String umwandeln (wenn die Zahl 24 auf dem Display
ausgegeben werden soll, muss die Zahl zur Ausgabe in zwei Zeichen umgewandelt
werden, nämlich 2 ́ und4 ́), z.B. mit

```
char zeile[17] = {};
int var = 0;
sprintf(zeile, "%i", var);
```

sprintf wandelt somit den Wert der Variablen „var“ in eine Zeichenkette, die in „zeile“
abgespeichert wird. Für die sprintf()-Funktion müssen Sie <stdio.h> einbinden.
Weitere Infos zur Nutzung des LCD finden Sie in Abschnitt E1.
