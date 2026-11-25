# ProgettoLDP
Prova intermedia di programmazione - Favaro, Pasqualini

Lavoro svolto nel progetto:
- Pasqualini: sviluppo classi Minimum.h, Minimum.cpp, funzione getT in IOminimum
- Favaro: sviluppo classi Function.h, Function.cpp, altre funzioni in IOminimum

Abbiamo deciso di provare ad implementare un algoritmo per aggiornare in modo dinamico il passo a, creando una funzione apposita nella classe Minimum,
abbiamo cercato su internet dei modi per implementarlo, metto qui sotto dei link con alcune fonti.

Abbiamo dunque trovato ed utilizzato il metodo Armijo Backtracking Line Search applicato alla discesa del gradiente,
che cerca un passo "a" efficiente che rispetti la sequente disequazione: (che si trova così nel codice)

nextF <= fValue - c\*currentA*(gradNorm*gradNorm)

- nexF: passo successivo (p_k+1 = p_k - a * Grad(p_k))
- fValue: passo attuale
- c: una costante che varia tra 0,1 (Costante di Armijo)
- currentA: "a" attuale
- gradNorm*gradNorm: è la norma del gradiente alla seconda 

L'algoritmo consiste nel:
1) calcolare il valore del prossimo passo usando "a" attuale
2) verificare tramite la disequazione che questo "a" sia considerato efficiente
3) aggiornare "a", dimezzandolo per semplicità, nel caso in cui non sia efficiente

Link:
- https://www.dmsa.unipd.it/~zilli/Line_search.pdf, mostra la formula generale di Armijo
- https://youtu.be/4qDt4QUl4zE?si=KDKTvEHeXJ9cx8xQ
- https://vaswanis.github.io/409_981-F22/L3.pdf, mostra la formula applicata alla discesa del gradiente

Per salvare le funzioni e caricarle, abbiamo usato una mappa. Questo ci permette ci aggiungere e modificare facilmente eventuali funzioni semplicemente modificando IOminimum.cpp

Un oggetto funzione contiene i seguenti campi: 
  - ID
  - testo della funzione
  - espressione eseguibile della funzione f(x, y)
  - espressione eseguibile della derivata parziale df/dx
  - espressione eseguibile della derivata parziale df/dy
  - valore minimo atteso della funzione

Per espressione eseguibile intendiamo una lambda function (di cui lasciamo i link per la documentazione qui sotto).
Questo ci permette di eseguire i calcoli del valore della funzione e del gradiente in maniere rapida e attraverso codice molto pulito.

Link:
 - https://www.w3schools.com/cpp/cpp_functions_lambda.asp
 - https://en.cppreference.com/cpp/language/lambda