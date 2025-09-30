Hej Gecko.
I den her kode fremviser jeg, hvordan rock, paper, scissors, lizard og spock kan spilles i VS Codium. 
Til at starte med definer jeg først min winning score, finder typedef enum for mine shapes og giver dem nogle characther navne.
Jeg comparer, hvilken shape agent og player vælger og beslutter hvilke characther der slår hvem ved brug af logical AND/OR og en "if" statement. 
I selve spillet vælger player sin egen shape, men Agenten får en random shape ud for "srand", som er baseret på tiden (Derfor vil den altid være anderledes).
Playeren har mulighed for at vælge imellem 0-4 (5 shapes). Hvis playeren vælger noget, som ikke er indenfor choices, bliver der printet "invalid choice" ud. 
Vi finder resultatet ved at compare shapes'ne, som sagt tidligere, og det bedømmer hvem der vinder runden . Vinder af runden bliver vist med printf. 
Ud for winning score får man vide om "You won" eller "Agent won".
I meny'en bruger jeg en raw string literal til at printe "welcome". 
Ud for det har player'en valgmulighederne 's' for at starte spillet ("int play game", som jeg lavede tidligere) eller 'e' for at Exit.
Hvis du ikke siger en af de to valgmuligheder får du en "unknown meny option, try again".
