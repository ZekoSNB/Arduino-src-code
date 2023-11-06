#define ON_OFF 64
#define PLAY_PAUSE 65
#define BRIGHTNESS_UP 92
#define BRIGHTNESS_DOWN 93
#define RED 88
#define GREEN 89
#define BLUE 69
#define WHITE 68
#define DARK_ORANGE 84
#define BRIGHT_GREEN 85
#define BRIGHT_BLUE 73
#define WHITE_1 72
#define WHITE_2 76
#define ORANGE 80
#define AQUA 81
#define DARK_PURPLE 77
#define DARK_YELLOWISH 28
#define DARK_AQUA 29
#define MAGENTA 30
#define WHITE_BLUE1 31
#define WHITE_BLUE2 27
#define YELLOW 24
#define DARK_GREEN_AQUA 25
#define BRIGHT_PURPLE 26
#define ADD_RED 20
#define SUBTRACT_RED 16
#define ADD_GREEN 21
#define SUBTRACT_GREEN 17
#define ADD_BLUE 22
#define SUBTRACT_BLUE 18
#define QUICKER 23
#define SLOWER 19
#define AUTO 15
#define FLASH 11
#define JUMP3 4
#define JUMP7 5
#define FADE3 6
#define FADE7 7

int RED_PIN;
int GREEN_PIN;
int BLUE_PIN;

int brightness_diff = 25;

uint8_t red = 180;
uint8_t green = 0;
uint8_t blue = 255;
uint8_t count;

void init(int red_pin, int green_pin, int blue_pin){
    RED_PIN = red_pin;
    GREEN_PIN = green_pin;
    BLUE_PIN = blue_pin;
    pinMode(OUTPUT, RED_PIN);
    pinMode(OUTPUT, GREEN_PIN);
    pinMode(OUTPUT, BLUE_PIN);
}

void set_color(uint8_t R, uint8_t G, uint8_t B){
    red = R;
    green = G;
    blue = B;
    analogWrite(RED_PIN, R);
    analogWrite(GREEN_PIN, G);
    analogWrite(BLUE_PIN, B);
}

void on_off(){
    if (count % 2 == 1){
        count++;
        set_color(red, green, blue);
    }

    else{
        analogWrite(RED_PIN, 0);
        analogWrite(GREEN_PIN, 0);
        analogWrite(BLUE_PIN, 0);
        count++;
    }
    
}

void command_receive(uint16_t command){

    switch (command){

    case ON_OFF:
        on_off();
        break;

    case ADD_RED:
        if (red + brightness_diff > 255){
            break;
        }
        red = red + brightness_diff;
        set_color(red, green, blue);
    
    case SUBTRACT_RED:
        if (red - brightness_diff < 0) {
            break;
        }
        red = red - brightness_diff;
        set_color(red,green, blue);
    
    case ADD_GREEN:
        if (green + brightness_diff > 255){
            break;
        }
        green = green + brightness_diff;
        set_color(red, green, blue);
    
    case SUBTRACT_GREEN:
        if (green - brightness_diff < 0) {
            break;
        }
        green = green - brightness_diff;
        set_color(red,green, blue);

    case ADD_BLUE:
        if (blue + brightness_diff > 255){
            break;
        }
        blue = blue + brightness_diff;
        set_color(red, green, blue);
    
    case SUBTRACT_BLUE:
        if (blue - brightness_diff < 0) {
            break;
        }
        blue = blue - brightness_diff;
        set_color(red,green, blue);

    case BRIGHTNESS_UP:
        if (red + brightness_diff > 255 || green + brightness_diff > 255 || blue + brightness_diff > 255){
            break;
        }

        red = red + brightness_diff;
        green = green + brightness_diff;
        blue = blue + brightness_diff;
        set_color(red, green, blue);
        break;

    case BRIGHTNESS_DOWN:
        if (red - brightness_diff < 0 || green - brightness_diff < 0 || blue - brightness_diff < 0){
            break;
        }

        red = red - brightness_diff;
        green = green - brightness_diff;
        blue = blue - brightness_diff;
        set_color(red, green, blue);
        break;


    case RED:
        set_color(255, 0, 0);
        break;

    case BLUE:
        set_color(0, 0, 255);
        break;

    case GREEN:
        set_color(0, 255, 0);
        break;

    case WHITE:
        set_color(255, 255, 255);
        break;

    case DARK_ORANGE:
        set_color(255, 140, 0);
        break;
    
    case ORANGE:
        set_color(255, 165, 0);
        break;

    case YELLOW:
        set_color(255, 255, 0);
        break;

    case BRIGHT_GREEN:
        set_color(0, 255, 50);

    case AQUA:
        set_color(0, 255, 255);
        break;

    case DARK_AQUA:
        set_color(0, 180, 190);
        break;

    case DARK_GREEN_AQUA:
        set_color(0, 255, 240);
        break;

    case BRIGHT_BLUE:
        set_color(0, 25, 255);
        break;

    case DARK_PURPLE:
        set_color(255, 60, 240);
        break;

    case MAGENTA:
        set_color(255, 0, 255);
        break;

    case BRIGHT_PURPLE:
        set_color(255, 80, 255);
        break;

    case WHITE_1:
        set_color(255, 255, 255);
        break;

    case WHITE_2:
        set_color(255, 255, 255);
        break;

    case WHITE_BLUE1:
        set_color(255, 255, 255);
        break;

    case WHITE_BLUE2:
        set_color(255, 255, 255);
        break;

    default:
        set_color(0,0,0);
        break;
    }
}