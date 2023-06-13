#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <string>

using namespace sf;

//void move(Window& app, Sprite grid[][8], int i1, int i2, int i3, int i4, int x, int x1, int y, int y1) {
//    if (x - x1 != 0) {
//        for (int i = 1; i <= x1; i++) {
//            grid[i1][i2].move(x - i, y);
//           /* app.display();
//            Sleep(10);*/
//        }
//    }
//    if (y - y1 != 0) {
//        for (int i = 1; i <= y1; i++) {
//            grid[i1][i2].move(x, y - i);
//            //Sleep(100);
//        }
//    }
//    if (x1 - x != 0) {
//        for (int i = 1; i <= x; i++) {
//            grid[i3][i4].move(x1 - i, y1);
//            //Sleep(100);
//        }
//    }
//    if (y1 - y != 0) {
//        for (int i = 1; i <= y; i++) {
//            grid[i3][i4].move(x1, y1 - i);
//            //Sleep(100);
//        }
//    }
//}

void traverseArray(Sprite grid[][8], int& scoreCount) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i + 2 < 8 && grid[i][j].getTexture() == grid[i + 1][j].getTexture() && grid[i][j].getTexture() == grid[i + 2][j].getTexture()) {
                for (int k = i; k < 8; k++) {
                    if (grid[i][j].getTexture() == grid[k][j].getTexture()) {
                        grid[k][j].setColor(Color::Blue);
                        scoreCount++;
                    }
                    else {
                        break;
                    }
                }
            }
            if (j + 2 < 8 && grid[i][j].getTexture() == grid[i][j + 1].getTexture() && grid[i][j].getTexture() == grid[i][j + 2].getTexture()) {
                for (int k = j; k < 8; k++) {
                    if (grid[i][j].getTexture() == grid[i][k].getTexture()) {
                        grid[i][k].setColor(Color::Blue);
                        scoreCount++;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}

void deleteBlocks(Sprite grid[][8], Sprite animals[], int& scoreCount) {
    bool repeat = true;
    while (repeat) {
        repeat = false;
        for (int i = 7; i >= 0; i--) {
            for (int j = 0; j < 8; j++) {
                if (grid[j][i].getColor() == Color::Blue) {
                    repeat = true;
                    int k = 0;
                    for (k = i; k >= 0; k--) {
                        if (grid[j][k].getColor() != Color::Blue) {
                            break;
                        }
                    }

                    //std::cout << "Founded X: " << grid[j][k].getPosition().x << "\n";
                    //std::cout << "Founded Y: " << grid[j][k].getPosition().y << "\n";

                    //std::cout << "Current X: " << grid[j][i].getPosition().x << "\n";
                    //std::cout << "Current Y: " << grid[j][i].getPosition().y << "\n";

                    if (k >= 0) {
                        Sprite Temp = grid[j][k];
                        Temp.move(0, grid[j][i].getPosition().y - grid[j][k].getPosition().y);
                        grid[j][i].move(0, grid[j][k].getPosition().y - grid[j][i].getPosition().y);
                        //grid[j][i].move(0, 500);
                        grid[j][k] = grid[j][i];
                        grid[j][i] = Temp;
                    }


                    //std::cout << "Founded X: " << grid[j][k].getPosition().x << "\n";
                    //std::cout << "Founded Y: " << grid[j][k].getPosition().y << "\n";

                    //std::cout << "Current X: " << grid[j][i].getPosition().x << "\n";
                    //std::cout << "Current Y: " << grid[j][i].getPosition().y << "\n";


                    //std::cout << "Founded Value = " << k << '\n';
                    //if (grid[j][i-1]==)
                    //std::cout << i << '\t' << j << std::endl;

                    if (grid[j][0].getColor() == Color::Blue) {
                        grid[j][0] = animals[rand() % 7];
                        grid[j][0].move(j * 57, 0);
                    }


                    /* system("pause");
                     app.display();*/
                }
            }
        }
        if (repeat) {
            traverseArray(grid, scoreCount);
        }
    }
}

void getindex(int x,int y, int& index1, int& index2) {
    for (int i = 0; i < 8; i++) {
        if (x >= i * (54 + 3) && x <= (i + 1) * (54 + 3) - 3) {
            index1 = i;
            for (int j = 0; j < 8; j++) {
                if (y >= (j * (54 + 3)) && y <= (j + 1) * (54 + 3) - 3) {
                    index2 = j;
                }
            }
        }
    }
}

//
//void removeBlock(Sprite arr[][8], int i, int j) {
//    if ((i + 1 < 8 && arr[i][j].getTexture() == arr[i + 1][j].getTexture()) ||
//        /*(i - 1 >= 0 && arr[i][j].getTexture() == arr[i - 1][j].getTexture()) ||*/
//        (j + 1 < 8 && arr[i][j].getTexture() == arr[i][j + 1].getTexture()) 
//       /* (j - 1 >= 0 && arr[i][j].getTexture() == arr[i][j - 1].getTexture())*/) {
//        arr[i][j].setColor(Color::Black);
//    }
//    if (i + 1 < 8 && arr[i][j].getTexture() == arr[i + 1][j].getTexture()) {
//        removeBlock(arr, i + 1, j);
//        if (i + 1 == 7) {
//            arr[i + 1][j].setColor(Color::Black);
//        }
//    }
//    /*else if (i - 1 >= 0 && arr[i][j].getTexture() == arr[i - 1][j].getTexture()) {
//        removeBlock(arr, i - 1, j);
//    }*/
//    if (j + 1 < 8 && arr[i][j].getTexture() == arr[i][j + 1].getTexture()) {
//        removeBlock(arr, i, j + 1);
//        if (j + 1 == 7) {
//            arr[i][j+1].setColor(Color::Black);
//        }
//    }
//   /* else if (j - 1 >= 0 && arr[i][j].getTexture() == arr[i][j - 1].getTexture()) {
//        removeBlock(arr, i, j - 1);
//    }*/
//    return;
//}
//
//int getBlocks(Sprite arr[][8], int i, int j) {
//    if (i+1 < 8 && arr[i][j].getTexture() == arr[i + 1][j].getTexture()) {
//        if (i + 1 == 7) {
//            return getBlocks(arr, i + 1, j) + 2;
//        }
//        return getBlocks(arr, i + 1, j) + 2;
//    }
//    /*else if (i-1 >= 0 && arr[i][j].getTexture() == arr[i - 1][j].getTexture()) {
//        return getBlocks(arr, i - 1, j) + 1;
//    } */
//    else if (j + 1 < 8 && arr[i][j].getTexture() == arr[i][j + 1].getTexture()) {
//        if (j + 1 == 7) {
//            return getBlocks(arr, i, j+1) + 2;
//        }
//        return getBlocks(arr, i, j + 1) + 1;
//    }
//   /* else if (j - 1 >= 0 && arr[i][j].getTexture() == arr[i][j - 1].getTexture()) {
//        return getBlocks(arr, i, j - 1) + 1;
//    }*/
//    return 0;
//}
//
//void move(int from, int to, int col, Sprite arr[][8], Sprite animal[]) {
//    int diff = to - from;
//    for (int i = 0; to-i>=0 && from-i>=0; i++) {
//        arr[from - i][col].move(0, diff * 57);
//        arr[to - i][col].move(1000, 1000);
//        arr[to-i][col] = arr[from - i][col];
//    }
//    for (int i = diff - 1; i >= 0; i--) {
//        arr[i][col] = animal[rand() % 7];
//    }
//}



int main(){
    srand(time(NULL));
    int ts = 54; //tile size
    Vector2i offset(48, 24);
    srand(time(0));
    RenderWindow app(VideoMode(740, 480), "Menagerie");
    app.setFramerateLimit(60);
    Texture t1, t2;
    t1.loadFromFile("back.jpg");
    t2.loadFromFile("gems.jpg");
    Sprite background(t1), gems(t2), menu, Bar,Pass, Fail, Won;
    Texture camel, cat, bull, deer, elephant, giraffe, goat, m, bar, barfill, pass, fail, won;
    Sprite animals[7];
    Sprite grid[8][8];
    
    camel.loadFromFile("./camel.jpg");
    animals[0].setTexture(camel);
    bull.loadFromFile("./bull.jpg");
    animals[1].setTexture(bull);
    cat.loadFromFile("./cat.jpg");
    animals[2].setTexture(cat);
    deer.loadFromFile("./deer.jpg");
    animals[3].setTexture(deer);
    elephant.loadFromFile("./elephant.jpg");
    animals[4].setTexture(elephant);
    giraffe.loadFromFile("./giraffe.jpg");
    animals[5].setTexture(giraffe);
    goat.loadFromFile("./goat.jpg");
    animals[6].setTexture(goat);
    m.loadFromFile("./menu.png");
    menu.setTexture(m);
    bar.loadFromFile("./bar.png");
    Bar.setTexture(bar);
    Bar.setPosition(490, 10);
    barfill.loadFromFile("./barFiller.png");
    pass.loadFromFile("./pass.png");
    fail.loadFromFile("./fail.png");
    Pass.setTexture(pass);
    Fail.setTexture(fail);
    won.loadFromFile("./won.png");
    Won.setTexture(won);

    Sprite progressBar[8];
    for (int i = 0; i < 8; i++) {
        progressBar[i].setTexture(barfill);
        progressBar[i].setPosition(500 + (i * 25), 16);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            grid[i][j] = animals[rand() % 7];
            grid[i][j].setPosition(i * (54 + 3), j * (54 + 3));
        }
    }

    

    Event e;
    int i1 = -1, i2 = -1, i3 = -1, i4 = -1;
    bool flag = false;
    bool gameStarted = false;
    bool menuShow = true;
    bool showLevelPass = false;
    bool showLevelFail = false;
    int progress = 0;
    int noOfTurns = 20;
    bool sign;
    bool lvl1 = true;
    bool lvl2 = false;
    bool gameWon = false;
    int points = 0;
    bool isTimeTrial = false;
    Text scoreTitle, score, turns, multiplier, TimeLeft;
    Font font;
    font.loadFromFile("./arial.ttf");
    scoreTitle.setFont(font);
    scoreTitle.setString("Score: ");
    scoreTitle.setCharacterSize(24);
    scoreTitle.setPosition(500, 50);
    scoreTitle.setOutlineColor(Color::Green);
    scoreTitle.setFillColor(Color::White);
    scoreTitle.setStyle(Text::Bold);

    score.setFont(font);
    score.setString(std::to_string(points));
    score.setCharacterSize(40);
    score.setPosition(500, 80);
    score.setOutlineColor(Color::Green);
    score.setFillColor(Color::White);
    score.setStyle(Text::Bold);

    turns.setFont(font);
    turns.setString("Turns Left: " + std::to_string(noOfTurns));
    turns.setCharacterSize(24);
    turns.setPosition(500, 140);
    turns.setOutlineColor(Color::Green);
    turns.setFillColor(Color::White);
    turns.setStyle(Text::Bold);

    multiplier.setFont(font);
    multiplier.setString("x" + std::to_string(1));
    multiplier.setCharacterSize(70);
    multiplier.setPosition(350, 220);
    multiplier.setOutlineColor(Color::Green);
    multiplier.setFillColor(Color::White);
    multiplier.setStyle(Text::Bold);

    int lvl2Time = 120;
    int scoreCount = 0;

    TimeLeft.setFont(font);
    TimeLeft.setString("Time Left: " + std::to_string(lvl2Time));
    TimeLeft.setCharacterSize(25);
    TimeLeft.setPosition(500, 190);
    TimeLeft.setOutlineColor(Color::Green);
    TimeLeft.setFillColor(Color::White);
    TimeLeft.setStyle(Text::Bold);

    time_t tim = time(NULL);
   
    time_t lvl2StartTime = time(NULL);

    

    while (app.isOpen()) {
        if (gameWon) {
            app.draw(Won);
            while (app.pollEvent(e)) {
                if (e.type == Event::Closed)
                    app.close();

                if (e.type == Event::MouseButtonPressed || e.type == Event::MouseButtonReleased) {
                    if (e.type == Event::MouseButtonPressed)
                        if (e.key.code == Mouse::Left) {
                            //grid[0][0].move(0, 50);
                            //std::cout <<
                            //getindex(e.mouseButton.x, e.mouseButton.y, i1, i2);
                            i1 = e.mouseButton.x;
                            i2 = e.mouseButton.y;

                            if (i1 >= 73 && i1 <= 345 && i2 >= 239 && i2 <= 352) {
                                menuShow = true;
                                gameWon = false;
                            }
                            else if (i1 >= 371 && i1 <= 654 && i2 >= 239 && i2 <= 352) {
                                lvl1 = true;
                                lvl2 = false;
                                gameWon = false;
                                gameStarted = true;
                                progress = 0;
                                if (isTimeTrial) {
                                    progress = 25;
                                }
                                noOfTurns = 20;
                                points = 0;
                            }
                            //<< std::endl;
                            i1 = i2 = -1;
                        }
                }
            }
        }
        if (showLevelFail) {
            app.draw(Fail);
            while (app.pollEvent(e)) {
                if (e.type == Event::Closed)
                    app.close();

                if (e.type == Event::MouseButtonPressed || e.type == Event::MouseButtonReleased) {
                    if (e.type == Event::MouseButtonPressed)
                        if (e.key.code == Mouse::Left) {
                            //grid[0][0].move(0, 50);
                            //std::cout <<
                            //getindex(e.mouseButton.x, e.mouseButton.y, i1, i2);
                            i1 = e.mouseButton.x;
                            i2 = e.mouseButton.y;

                            if (i1 >= 73 && i1 <= 345 && i2 >= 239 && i2 <= 352) {
                                menuShow = true;
                                showLevelFail = false;
                                lvl1 = true;
                                lvl2 = false;
                                lvl2Time = 120;
                                progress = 0;
                                points = 0;
                                noOfTurns = 20;
                            }
                            else if (i1 >= 371 && i1 <= 654 && i2 >= 239 && i2 <= 352) {
                                showLevelFail = false;
                                gameStarted = true;
                                progress = 0;
                                if (isTimeTrial) {
                                    progress = 25;
                                }
                                noOfTurns = 20;
                                points = 0;
                            }
                            //<< std::endl;
                            i1 = i2 = -1;
                        }
                }
            }
        }

        if (showLevelPass) {
            app.draw(Pass);
            while (app.pollEvent(e)) {
                if (e.type == Event::Closed)
                    app.close();

                if (e.type == Event::MouseButtonPressed || e.type == Event::MouseButtonReleased) {
                    if (e.type == Event::MouseButtonPressed)
                        if (e.key.code == Mouse::Left) {
                            //grid[0][0].move(0, 50);
                            //std::cout <<
                            //getindex(e.mouseButton.x, e.mouseButton.y, i1, i2);
                            i1 = e.mouseButton.x;
                            i2 = e.mouseButton.y;

                            if (i1 >= 73 && i1 <= 345 && i2 >= 239 && i2 <= 352) {
                                menuShow = true;
                                showLevelPass = false;
                                lvl1 = true;
                                lvl2 = false;
                            }
                            else if (i1 >= 371 && i1 <= 654 && i2 >= 239 && i2 <= 352) {
                                lvl1 = false;
                                lvl2 = true;
                                lvl2Time = 120;
                                lvl2StartTime = time(NULL);
                                showLevelPass = false;
                                gameStarted = true;
                                progress = 0;
                                if (isTimeTrial) {
                                    progress = 25;
                                }
                                noOfTurns = 20;
                            }
                            //<< std::endl;
                            i1 = i2 = -1;
                        }
                }
            }
        }

        if (menuShow) {
            
            app.draw(menu);
            
            while (app.pollEvent(e)) {
                if (e.type == Event::Closed)
                    app.close();

                if (e.type == Event::MouseButtonPressed || e.type == Event::MouseButtonReleased) {
                    if (e.type == Event::MouseButtonPressed)
                        if (e.key.code == Mouse::Left) {
                            //grid[0][0].move(0, 50);
                            //std::cout <<
                            //getindex(e.mouseButton.x, e.mouseButton.y, i1, i2);
                            i1 = e.mouseButton.x;
                            i2 = e.mouseButton.y;

                            //std::cout << i1 << i2 << std::endl;
                            if (i1 >= 73 && i1 <= 345 && i2 >= 239 && i2 <= 352) {
                                menuShow = false;
                                gameStarted = true;
                                showLevelPass = false;
                                showLevelFail = false;
                                progress = 0;
                                noOfTurns = 20;
                                lvl1 = true;
                                lvl2 = false;
                                gameWon = false;
                                points = 0;
                                isTimeTrial = false;
                                lvl2Time = 120;
                                scoreCount = 0;
                            }
                            else if (i1 >= 371 && i1 <= 654 && i2 >= 239 && i2 <= 352) {
                                menuShow = false;
                                gameStarted = true;
                                progress = 25;
                                isTimeTrial = true;
                                showLevelPass = false;
                                showLevelFail = false;
                                noOfTurns = 20;
                                lvl1 = true;
                                lvl2 = false;
                                gameWon = false;
                                points = 0;
                                lvl2Time = 120;
                                scoreCount = 0;
                            }
                            //<< std::endl;
                            i1 = i2 = -1;
                        }
                }
            }
        }

        if (gameStarted) {
            traverseArray(grid, scoreCount);
            deleteBlocks(grid, animals, scoreCount);
            scoreCount = 0;

            if (lvl2 && (difftime(time(NULL),lvl2StartTime)>=1)) {
                lvl2StartTime = time(NULL);
                lvl2Time--;
                TimeLeft.setString("Time Left: " + std::to_string(lvl2Time));
            }

            if (isTimeTrial && difftime(time(NULL), tim) >= 10){
                tim = time(NULL);
                progress -= 6;
            }
            app.draw(background);
            app.draw(gems);
            app.draw(Bar);
            app.draw(scoreTitle);
            app.draw(score);
            app.draw(turns);
            if (lvl2) {
                app.draw(TimeLeft);
            }
            int n = progress;
            for (int i = 0; i < 8; i++) {
                if (n > 0) {
                    app.draw(progressBar[i]);
                }
                n -= 6;
            }
            
            if (noOfTurns <= 0 || progress<0 || lvl2Time<0) {
                showLevelFail = true;
                gameStarted = false;
            }

            if (lvl2) {
                if (progress >= 50) {
                    gameWon = true;
                    gameStarted = false;
                }
            }

            if (lvl1 == true ) {
                if (progress >= 50) {
                    showLevelPass = true;
                    gameStarted = false;
                }
            }

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    app.draw(grid[i][j]);
                }
            }

            score.setString(std::to_string(points));
            turns.setString("Turns Left: " + std::to_string(noOfTurns));

            while (app.pollEvent(e)) {
                if (e.type == Event::Closed)
                    app.close();

                if (e.type == Event::MouseButtonPressed || e.type == Event::MouseButtonReleased) {
                    if (e.type == Event::MouseButtonPressed)
                        if (e.key.code == Mouse::Left) {
                            //grid[0][0].move(0, 50);
                            //std::cout <<
                            getindex(e.mouseButton.x, e.mouseButton.y, i1, i2);
                            //<< std::endl;
                        }
                    if (e.type == Event::MouseButtonReleased)
                        if (e.key.code == Mouse::Left) {
                            /*std::cout << e.mouseButton.x << std::endl;
                            std::cout << e.mouseButton.y << std::endl;*/
                            getindex(e.mouseButton.x, e.mouseButton.y, i3, i4);
                        }
                    std::cout << i1 << '\t' << i2 << '\t' << i3 << '\t' << i4 << std::endl;
                    if (!(i1 == -1 || i2 == -1 || i3 == -1 || i4 == -1)) {
                        if (i3 == i1 && i2 != i4) {
                            if (i2 == i4 + 1 || i2 == i4 - 1) {
                                flag = true;
                            }
                        }
                        if (i2 == i4 && i1 != i3) {
                            if (i3 == i1 + 1 || i3 == i1 - 1) {
                                flag = true;
                            }
                        }
                        if (flag) {
                            int x = grid[i3][i4].getPosition().x;
                            int y = grid[i3][i4].getPosition().y;
                            int x1 = grid[i1][i2].getPosition().x;
                            int y1 = grid[i1][i2].getPosition().y;

                            /*if (i1==i3 && i2==i4-1 && grid[i3][i4].getTexture() == grid[])*/

                           /* move(app, grid, i1, i2, i3, i4, x, x1, y, y1);*/
                            grid[i1][i2].move(x - x1, y - y1);
                            grid[i3][i4].move(x1 - x, y1 - y);

                            Sprite temp(grid[i1][i2]);
                            //temp.setColor(Color::Red);
                            grid[i1][i2] = grid[i3][i4];
                            grid[i3][i4] = temp;

                            noOfTurns--;

                            
                            flag = false;
                            int num = 0;

                            sign = false;

                            for (int i = 0; i < 8; i++) {
                                for (int j = 0; j < 8; j++) {
                                    if (i + 2 < 8 && grid[i][j].getTexture() == grid[i + 1][j].getTexture() && grid[i][j].getTexture() == grid[i + 2][j].getTexture()) {
                                        for (int k = i; k < 8; k++) {
                                            if (grid[i][j].getTexture() == grid[k][j].getTexture()) {
                                                grid[k][j].setColor(Color::Blue);
                                                scoreCount++;
                                                //grid[k][j].move(0, 500);
                                                /*for (int a = k+1, b = k; a >= 0; b--, a--) {
                                                    grid[k][j] = grid[a][j];
                                                    grid[a][j].move(0, 57);
                                                }*/
                                            }
                                            else {
                                                break;
                                            }
                                        }
                                        sign = true;
                                    }
                                    if (j + 2 < 8 && grid[i][j].getTexture() == grid[i][j + 1].getTexture() && grid[i][j].getTexture() == grid[i][j + 2].getTexture()) {
                                        for (int k = j; k < 8; k++) {
                                            if (grid[i][j].getTexture() == grid[i][k].getTexture()) {
                                                grid[i][k].setColor(Color::Blue);
                                                scoreCount++;
                                                //for (int a = k + 1, b = k; a >= 0; b--, a--) {
                                                //    grid[k][j] = grid[a][j];
                                                //    //grid[a][j].move(0, 57);
                                                //}
                                            }
                                            else {
                                                break;
                                            }
                                        }
                                        sign = true;
                                    }
                                }
                            }

                            if (!sign) {
                                std::cout << "No Sign\n";

                                Sprite temp(grid[i1][i2]);
                                //temp.setColor(Color::Red);
                                grid[i1][i2] = grid[i3][i4];
                                grid[i3][i4] = temp;

                                noOfTurns++;

                                grid[i1][i2].move(x1 - x, y1 - y);
                                grid[i3][i4].move(x - x1, y - y1);
                                
                                i1 = i2 = i3 = i4 = -1;
                            }

                            if (sign) {
                                i1 = i2 = i3 = i4 = -1;
                                //std::cout << "Progress: " << progress << "\n";
                                if (scoreCount > 3) {
                                    progress += (scoreCount * 2);
                                    multiplier.setString("Hooray! x" + std::to_string(scoreCount - 2));
                                    app.draw(multiplier);
                                    points += scoreCount*(scoreCount-2);
                                }
                                else {
                                    progress+=scoreCount;
                                    points += scoreCount;
                                }
                                scoreCount = 0;
                                //std::cout << "Progress: " << progress << "\n";
                                sign = false;

                                deleteBlocks(grid, animals, scoreCount);

                                
                                
// 
                            //    for (int i = 7; i >= 0; i--) {
                            //        for (int j = 0; j < 8; j++) {
                            //            if (grid[i][j].getColor() == Color::Black) {
                            //                int k = i;
                            //                for (k = 7; k >= 0; k--) {
                            //                    if (grid[k][j].getColor() != Color::Black) {
                            //                        break;
                            //                    }
                            //                }
                            //                //move(k, i, j, grid, animals);

                            //                //grid[k][j].move(grid[i][j].getPosition().x, ((i - k)* (480 - 54 + 3)));
                            //                /*for (int l = k, t = 0; l >= 0; l--, t++) {
                            //                    grid[i - t][j] = grid[l][j];
                            //                }*/
                            //                /*grid[i]*/



                            //            }
                            //        }
                            //    }
                            }


                            //int times = getBlocks();


                        }




                        //grid[i1][i2].setPosition(300, 300);
                        /*grid[i3][i4].setPosition(350, 300);*/
                        /*temp = grid[i1][i2];
                        grid[i1][i2] = grid[i3][i4];
                        grid[i3][i4] = temp;*/
                        /*for (int i = 0; i < 8; i++) {
                            for (int j = 0; j < 8; j++) {
                                app.draw(grid[i][j]);
                            }
                        }*/
                        /*grid[i1][i2] = grid[0][0];
                        grid[i1][i2].setPosition(100, 550);
                        grid[i3][i4] = grid[0][0];*/

                    }
                }
            }
        }
        
        app.display();
    }
    return 0;
}


