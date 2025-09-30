#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// hvor mange point der skal til for at vinde
#define WINNING_SCORE 5

// enum for shapes
typedef enum { ROCK = 0, LIZARD, SCISSORS, PAPER, SPOCK, SHAPE_COUNT } Shape;

// navne på shapes
const char *shape_names[] = {"🪨", "🦎", "✂️", "🗒️", "🖖"};

// sammenlign spillerens og agentens valg
int compare_shapes(Shape player, Shape agent) {
  if (player == agent)
    return 0;

  if ((player == ROCK && (agent == SCISSORS || agent == LIZARD)) ||
      (player == LIZARD && (agent == PAPER || agent == SPOCK)) ||
      (player == SCISSORS && (agent == LIZARD || agent == PAPER)) ||
      (player == PAPER && (agent == ROCK || agent == SPOCK)) ||
      (player == SPOCK && (agent == ROCK || agent == SCISSORS))) {
    return 1;
  }
  return -1;
}

// læs et heltal fra stdin via getchar()
int read_int() {
  int num = 0;
  int ch;
  int valid = 0;

  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (ch >= '0' && ch <= '9') {
      num = num * 10 + (ch - '0');
      valid = 1;
    } else {
      // ugyldigt tegn => returnér -1
      while (ch != '\n' && ch != EOF) {
        ch = getchar(); // ryd resten af linjen
      }
      return -1;
    }
  }
  return valid ? num : -1;
}

// spillet
void play_game() {
  int player_score = 0, agent_score = 0;

  srand((unsigned)time(NULL));

  while (player_score < WINNING_SCORE && agent_score < WINNING_SCORE) {
    printf("\nSelect a shape:\n");
    printf("0%s || 1%s || 2%s || 3%s || 4%s : ", shape_names[ROCK],
           shape_names[LIZARD], shape_names[SCISSORS], shape_names[PAPER],
           shape_names[SPOCK]);

    int choice = read_int();
    if (choice < 0 || choice >= SHAPE_COUNT) {
      printf("❌ Invalid choice. Try again.\n");
      continue;
    }

    Shape player = (Shape)choice;
    Shape agent = (Shape)(rand() % SHAPE_COUNT);

    printf("Agent: %d%s\n", agent, shape_names[agent]);

    int result = compare_shapes(player, agent);
    if (result == 1) {
      player_score++;
    } else if (result == -1) {
      agent_score++;
    }

    printf("👫:🤖  %d:%d\n", player_score, agent_score);
  }

  if (player_score == WINNING_SCORE) {
    printf("🏆 You won!\n");
  } else {
    printf("🤖 Agent won!\n");
  }
}

int main(void) {
  // brug af en raw string literal (C11-standard)
  const char *welcome = R"(
Welcome to 🪨 ✂️ 🗒️ 🖖 🦎 !
(s) Single player
(e) Exit
)";

  while (1) {
    printf("%s", welcome);
    printf("Select an item: ");

    int ch = getchar();
    while (getchar() != '\n')
      ; // ryd buffer

    if (ch == 's') {
      printf("Starting game 🎉\n");
      play_game();
      break; // afslut efter spil
    } else if (ch == 'e') {
      printf("Bye 👋\n");
      break;
    } else {
      printf("❌ Unknown menu option '%c'. Try again.\n", ch);
    }
  }

  return 0;
}
