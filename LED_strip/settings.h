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

#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 9

float brightness_diff = 25;
uint8_t red = 180;
uint8_t green = 0;
uint8_t blue = 255;
int speed = 1000;
uint8_t count;

void set_color(uint8_t R, uint8_t G, uint8_t B){
    analogWrite(RED_PIN, R);
    analogWrite(GREEN_PIN, G);
    analogWrite(BLUE_PIN, B);
}

void flashing(){
    while(true){
        set_color(255,255,255);
        delay(speed);
        set_color(0,0,0);
        delay(speed);
    }
}

void on_off(){
    if (count % 2 == 1){
        count++;
        set_color(255, 255, 255);
    }

    else{
        analogWrite(RED_PIN, 0);
        analogWrite(GREEN_PIN, 0);
        analogWrite(BLUE_PIN, 0);
        count++;
    }
    
}

void command_receive(int command){

    switch (command){

    case ON_OFF:
        on_off();
        
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
    
    case FLASH:
        flashing();
        break;

    default:
        break;
    }
}