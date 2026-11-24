# ProgettoLDP
Prova intermedia di programmazione - Favaro, Pasqualini

Lavoro svolto nel progetto:
- Pasqualini: sviluppo classi Minimum.h, Minimum.cpp, funzione getT in IOminimum
- Favaro: sviluppo classi Function.h, Function.cpp, altre funzioni in IOminimum

Ciao FM metti tu la parte in cui spieghi come gestiamo le funzioni? grazie token ciao

Abbiamo deciso di provare ad implementare un algoritmo per aggiornare in modo dinamico il passo a, creando una funzione apposita nella classe Minimum
abbiamo cercato su internet dei modi per implementarlo, metto qui sotto dei link con alcune fonti.

Abbiamo dunque trovato ed utilizzato Armijo Backtracking Line Search applicato alla discesa del gradiente,
cerca un passo a efficiente che rispetti la sequente disequazione: (che si trova così nel codice)

nextF <= fValue - c\*currentA*(gradNorm*gradNorm)

- nexF: passo successivo (p_k+1 = p_k - a * Grad(p_k))

Link:
- https://www.dmsa.unipd.it/~zilli/Line_search.pdf, mostra la formula generale di Armijo
- https://youtu.be/4qDt4QUl4zE?si=KDKTvEHeXJ9cx8xQ
- https://vaswanis.github.io/409_981-F22/L3.pdf, mostra la formula applicata alla discesa del gradiente

