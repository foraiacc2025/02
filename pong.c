#include <stdio.h>
#include <stdlib.h>

// Константы игры
const int WIDTH = 80;
const int HEIGHT = 25;
const int PADDLE_SIZE = 3;
const int WIN_SCORE = 21;

// Структуры для хранения состояния игры
struct Ball {
    int x;
    int y;
    int dx;
    int dy;
};

struct Paddle {
    int y;
    int score;
};

struct GameState {
    struct Ball ball;
    struct Paddle left_paddle;
    struct Paddle right_paddle;

    int vector_y;
    int game_over;
};

// Функции инициализации
struct GameState initialize_game() {
    struct GameState game;

    // Инициализация ракеток
    game.left_paddle.y = HEIGHT / 2 - PADDLE_SIZE / 2;
    game.right_paddle.y = HEIGHT / 2 - PADDLE_SIZE / 2;
    game.left_paddle.score = 0;
    game.right_paddle.score = 0;

    // Инициализация мяча
    game.ball.x = WIDTH / 2;
    game.ball.y = HEIGHT / 2;
    game.ball.dx = 1;
    game.ball.dy = 1;

    game.vector_y = 1;
    game.game_over = 0;

    return game;
}

void draw_field(struct GameState game) {  // Функции отрисовки

    system("clear");  // Очистка экрана

    for (int i = 0; i < WIDTH + 2; i++) {
        printf("-");
    }
    printf("\n");
    for (int y = 0; y < HEIGHT; y++) {  // Игровое поле
        printf("|");                    // Левая граница
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 && y >= game.left_paddle.y && y < game.left_paddle.y + PADDLE_SIZE) {
                printf("|");  // Отрисовка левой ракетки
                continue;
            }
            if (x == WIDTH - 1 && y >= game.right_paddle.y && y < game.right_paddle.y + PADDLE_SIZE) {
                printf("|");  // Отрисовка правой ракетки
                continue;
            }
            if (x == game.ball.x && y == game.ball.y) {  // Отрисовка мяча
                printf("O");
                continue;
            }
            printf(" ");
        }
        printf("|\n");  // Правая граница
    }
    for (int i = 0; i < WIDTH + 2; i++) {  // Нижняя граница
        printf("-");
    }
    printf("\n");
    printf("Score: Left %d - Right %d\n", game.left_paddle.score, game.right_paddle.score);  // Счет
    printf("Enter move (A/Z for left, K/M for right, SPACE to skip): \n");
}

// Функции обработки ввода
struct GameState process_input(struct GameState game) {
    char input;
    int valid_input = 0;
    while (!valid_input) {
        scanf("%c", &input);

        switch (input) {
            case 'a':
                if (game.left_paddle.y > 0) {
                    game.left_paddle.y--;
                }
                valid_input = 1;
                break;
            case 'z':
                if (game.left_paddle.y < HEIGHT - PADDLE_SIZE) {
                    game.left_paddle.y++;
                }
                valid_input = 1;
                break;
            case 'k':
                if (game.right_paddle.y > 0) {
                    game.right_paddle.y--;
                }
                valid_input = 1;
                break;
            case 'm':
                if (game.right_paddle.y < HEIGHT - PADDLE_SIZE) {
                    game.right_paddle.y++;
                }
                valid_input = 1;
                break;
            case ' ':
                valid_input = 1;  // Пропуск хода
                break;
        }
    }
    return game;
}

// Функции обновления игры
struct GameState update_ball(struct GameState game) {
    // Движение мяча
    game.ball.x += game.ball.dx;
    game.ball.y += game.ball.dy;

    // Отскок от верхней и нижней границ
    if (game.ball.y <= 0 || game.ball.y >= HEIGHT - 1) {
        game.ball.dy = -game.ball.dy;
    }

    // Проверка столкновения с левой ракеткой
    if (game.ball.x == 1 && game.ball.y >= game.left_paddle.y &&
        game.ball.y < game.left_paddle.y + PADDLE_SIZE) {
        game.ball.dx = -game.ball.dx;
    }

    // Проверка столкновения с правой ракеткой
    if (game.ball.x == WIDTH - 2 && game.ball.y >= game.right_paddle.y &&
        game.ball.y < game.right_paddle.y + PADDLE_SIZE) {
        game.ball.dx = -game.ball.dx;
    }

    // Проверка забития гола
    if (game.ball.x <= 0) {
        game.right_paddle.score++;
        game.ball.x = WIDTH / 2;
        game.ball.y = HEIGHT / 2;
        game.ball.dx = 1;
        game.vector_y = -game.vector_y;
        game.ball.dy = game.vector_y;
    }

    if (game.ball.x >= WIDTH - 1) {
        game.left_paddle.score++;
        game.ball.x = WIDTH / 2;
        game.ball.y = HEIGHT / 2;
        game.ball.dx = -1;
        game.vector_y = -game.vector_y;
        game.ball.dy = game.vector_y;
    }
    return game;
}

struct GameState check_game_over(struct GameState game) {
    if (game.left_paddle.score >= WIN_SCORE || game.right_paddle.score >= WIN_SCORE) {
        game.game_over = 1;
    }
    return game;
}

// Главная функция игры
void play_pong() {
    struct GameState game = initialize_game();

    while (!game.game_over) {
        draw_field(game);
        game = process_input(game);
        game = update_ball(game);
        game = check_game_over(game);
    }

    draw_field(game);
    printf("\nGame Over!\n");

    if (game.left_paddle.score > game.right_paddle.score) {
        printf("Left player wins! Congratulations!\n");
    } else {
        printf("Right player wins! Congratulations!\n");
    }
}

int main() {
    play_pong();
    return 0;
}
