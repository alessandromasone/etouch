# etouch

## Descrizione
Il progetto "etouch" è un comando scritto in linguaggio C che emula il comportamento del comando "touch" presente nei sistemi operativi Unix. Consente di creare file vuoti con la possibilità di personalizzare alcune opzioni.

## Requisiti
- Compilatore C compatibile (es. clang, GCC)
- Librerie standard C
- Sistema operativo compatibile con le chiamate di sistema utilizzate (es. Unix-like)

## Compilazione
Utilizzare un compilatore C per generare l'eseguibile a partire dal file sorgente `etouch.c`. Di seguito è riportato un esempio di compilazione utilizzando clang:

```
clang etouch.c -o etouch
```

## Utilizzo
Il comando "etouch" accetta una serie di argomenti da riga di comando, inclusi opzioni e nomi di file. Ecco la sintassi generale:

```
./etouch [-o] file1 file2 ...
```

- `-o`: Opzione facoltativa per abilitare la sovrascrittura dei file esistenti. Se specificata, il comando sovrascrive i file esistenti anziché ignorarli.

## Esempi
Ecco alcuni esempi di utilizzo del comando "etouch":

1. Creare un nuovo file chiamato "file1.txt":
```
./etouch file1.txt
```

2. Creare più file contemporaneamente:
```
./etouch file2.txt file3.txt file4.txt
```

3. Sovrascrivere un file esistente:
```
./etouch -o file1.txt
```

Si prega di notare che i nomi dei file possono essere specificati con o senza il percorso completo. Se un file esiste già e l'opzione `-o` non è specificata, il comando "etouch" ignorerà quel file e passerà al successivo.

## Contributi
Sono benvenuti i contributi a questo progetto! Se desideri contribuire, ti preghiamo di aprire una pull request o segnalare eventuali problemi nell'area delle issue.

## Licenza
Questo progetto è concesso in licenza ai sensi della licenza [MIT](LICENSE).