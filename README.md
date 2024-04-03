# Sistem de gestiune a unei liste de plata intr-o asociatie de locatari

    Programul cere de la tastatura anumite date relevante unei scari de bloc precum numele si consumul locatarilor de apa rece,
impreuna cu valoarea numerica si cantitativa a facturilor ca dupa sa calculeze totalul. Utilizatorul are posibilitatea de a
afisa toata tabela listei de plata, de a modifica un rand sau o coloana, sa stearga sau sa adauge (pana in limita posibila)
locatari sau facturi.
### Tema 0

- [x] Nume proiect (poate fi schimbat ulterior)
- [x] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [x] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi
- [x] constructori de inițializare
- [x] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
- [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor
- [ ] pentru o altă clasă: toate cele 5 funcții membru speciale 
- [x] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [x] cât mai multe `const` (unde este cazul)
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [x] scenariu de utilizare a claselor definite:
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [ ] tag de `git`: de exemplu `v0.1`
- [ ] serviciu de integrare continuă (CI); exemplu: GitHub Actions