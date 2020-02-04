#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
int v[10],t[5],ideal[5];
float timp[25];
bool verif[10],verifbuton[10];
int cntrM=0,d=255;
int xx=-1;
int indtime=10;
float timpout;
void Hanoi(int m, char a, char b, char c, int ind);
void asteapta(float timex)
{
    sf::Time time;
    sf::Clock clock;
    time=clock.restart();
    while(time.asSeconds()<timex)
    time=clock.getElapsedTime();

}
struct patrate_automat
{
    sf::RectangleShape s[10];
    int vf;
}S[5];
struct teme
{
    sf::Texture texture_fundal;
    sf::Sprite fundal;
    sf::Texture texture_resize;
    sf::Sprite t_resize;
    sf::Texture textura;
}T[10];
struct butoane_meniu_principal
{
    sf::Texture texture_buton;
    sf::Sprite buton;
}B[5];
struct mutari
{
    int m_plecare;
    int m_sosire;
    int x;
    int y;
}M[300];
sf::Vector2i screenDimensions(1000,800);
sf::RenderWindow Window;
sf::Texture pTexture1;
sf::Sprite Background1;

sf::RectangleShape s1[10];
sf::RectangleShape s2[10];
sf::RectangleShape s3[10];
void initializare_patrate()
{
    int red,green,blue;
    s1[0].setSize(sf::Vector2f(200,40)); S[1].s[0].setSize(sf::Vector2f(200,40));
    red=rand()%255; blue=rand()%255; green=rand()%255;
    s1[0].setFillColor(sf::Color(red,green,blue)); S[1].s[0].setFillColor(sf::Color(red,green,blue));
    s1[0].setPosition(100,600); S[1].s[0].setPosition(100,600);
    s1[0].setTexture(NULL); S[1].s[0].setTexture(NULL);
    s2[0].setTexture(NULL); S[2].s[0].setTexture(NULL);
    s3[0].setTexture(NULL); S[3].s[0].setTexture(NULL);
    for(int i=1;i<8;i++ )
    {
    sf::Vector2f saize;
    sf::Vector2f position;
    saize=s1[i-1].getSize();
    position=s1[i-1].getPosition();
    s1[i].setSize(sf::Vector2f(saize.x-20,40)); S[1].s[i].setSize(sf::Vector2f(saize.x-20,40));
    red=rand()%255; blue=rand()%255; green=rand()%255;
    s1[i].setFillColor(sf::Color(red,green,blue));  S[1].s[i].setFillColor(sf::Color(red,green,blue));
    s1[i].setPosition(position.x+10,position.y-40); S[1].s[i].setPosition(position.x+10,position.y-40);
    s1[i].setTexture(NULL); S[1].s[i].setTexture(NULL);
    s2[i].setTexture(NULL); S[2].s[i].setTexture(NULL);
    s3[i].setTexture(NULL); S[3].s[i].setTexture(NULL);


    }
}

int main()
{
     srand(time(0));
      sf::Clock clock;
      sf::Clock clock1;
     float frameCounter=0, frameSpeed=500;
     float frameCounter1=0, frameSpeed1=500;
     int xa,ya;
     for(int i=1;i<=20;i++)
        timp[i]=i;
     int a=2,ind=0;
     S[2].vf=-1; S[3].vf=-1;
     sf::SoundBuffer soundBuffer;
     sf::Sound sound;
     sf::SoundBuffer soundBuffer1;
     sf::Sound sound1;
     if(!soundBuffer.loadFromFile("error.wav"))
       std::cout<<"Error"<<'\n';
     if(!soundBuffer1.loadFromFile("tile.wav"))
       std::cout<<"Error"<<'\n';
     sound.setBuffer(soundBuffer);
     sound1.setBuffer(soundBuffer1);

     sf::Music music;
     if(!music.openFromFile("fundal_hanoi.ogg"))
        std::cout<<"Error"<<'\n';
     music.setLoop(true);




     Window.create(sf::VideoMode(screenDimensions.x,screenDimensions.y),"Turnurile din Hanoi", sf::Style::Close | sf::Style::Titlebar );
     sf::Texture pTexture;
     sf::Sprite Background;



     sf::Texture pTexture4;
     sf::Sprite titlu;
     sf::Texture pTexture5;
     sf::Sprite arrow_left;
     sf::Texture pTexture6;
     sf::Sprite arrow_right;
     sf::Texture pTexture11;
     sf::Sprite arrow_left_1;
     sf::Texture pTexture12;
     sf::Sprite arrow_right_1;
     sf::Texture pTexture8[3];
     sf::Sprite audio[3];
     sf::Texture pTexture9;
     sf::Sprite lemn;
     sf::Texture cloud_textura;
     sf::Sprite cloud;

     if(!cloud_textura.loadFromFile("cloud.png"))
        std::cout<<"Cloud"<<'\n';
     if(!pTexture.loadFromFile("background.png"))
        std::cout<<"Error "<<'\n';
     if(!T[1].texture_fundal.loadFromFile("background_clasic.png"))
        std::cout<<"Error "<<'\n';
     if(!T[2].texture_fundal.loadFromFile("background_wood.png"))
        std::cout<<"Error "<<'\n';
     if(!T[3].texture_fundal.loadFromFile("background_egypt.png"))
        std::cout<<"Error "<<'\n';
     if(!T[4].texture_fundal.loadFromFile("background_snow.png"))
        std::cout<<"Error "<<'\n';
     if(!T[5].texture_fundal.loadFromFile("background_brick.png"))
        std::cout<<"Error "<<'\n';
     if(!T[6].texture_fundal.loadFromFile("background_carpet.png"))
        std::cout<<"Error "<<'\n';
     if(!T[1].texture_resize.loadFromFile("clasic_resize.png"))
        std::cout<<"Error "<<'\n';
     if(!T[2].texture_resize.loadFromFile("wood_resize.png"))
        std::cout<<"Error "<<'\n';
     if(!T[3].texture_resize.loadFromFile("egypt_resize.png"))
        std::cout<<"Error "<<'\n';
     if(!T[4].texture_resize.loadFromFile("snow_resize.png"))
        std::cout<<"Error "<<'\n';
     if(!T[5].texture_resize.loadFromFile("brick_resize.png"))
        std::cout<<"Error "<<'\n';
     if(!T[6].texture_resize.loadFromFile("carpet_resize.png"))
        std::cout<<"Error "<<'\n';
     if(!T[2].textura.loadFromFile("wood.png"))
        std::cout<<"Error "<<'\n';
     if(!T[3].textura.loadFromFile("egypt.png"))
        std::cout<<"Error "<<'\n';
     if(!T[4].textura.loadFromFile("snow.png"))
        std::cout<<"Error "<<'\n';
     if(!T[5].textura.loadFromFile("brick.png"))
        std::cout<<"Error "<<'\n';
     if(!T[6].textura.loadFromFile("carpet.png"))
        std::cout<<"Error "<<'\n';
     cloud.setTexture(cloud_textura);

     for(int i=1;i<=6;i++)
     {
        T[i].fundal.setTexture(T[i].texture_fundal);
        T[i].t_resize.setTexture(T[i].texture_resize);
     }
     T[1].t_resize.setPosition(100,350);
     sf::Vector2f saize;
     T[2].t_resize.setPosition(T[1].t_resize.getPosition().x+T[1].t_resize.getLocalBounds().width+10,350);
     T[3].t_resize.setPosition(T[2].t_resize.getPosition().x+T[2].t_resize.getLocalBounds().width+10,350);
     T[4].t_resize.setPosition(100,T[1].t_resize.getPosition().y+T[1].t_resize.getLocalBounds().height+10);
     T[5].t_resize.setPosition(T[4].t_resize.getPosition().x+T[4].t_resize.getLocalBounds().width+10,T[1].t_resize.getPosition().y+T[1].t_resize.getLocalBounds().height+10);
     T[6].t_resize.setPosition(T[5].t_resize.getPosition().x+T[5].t_resize.getLocalBounds().width+10,T[1].t_resize.getPosition().y+T[1].t_resize.getLocalBounds().height+10);
     sf::Texture help_textura;
     sf::Sprite help;
     sf::Texture help_text_textura;
     sf::Sprite help_text;
     if(!help_textura.loadFromFile("help.png"))
        std::cout<<"Error"<<'\n';
     if(!help_text_textura.loadFromFile("help_text.png"))
        std::cout<<"Error"<<'\n';
     if(!B[1].texture_buton.loadFromFile("button.png"))
         std::cout<<"Error "<<'\n';
     if(!B[2].texture_buton.loadFromFile("button_despre.png"))
         std::cout<<"Error "<<'\n';
     if(!pTexture4.loadFromFile("titlu.png"))
         std::cout<<"Error "<<'\n';
     if(!pTexture5.loadFromFile("arrow left.png"))
         std::cout<<"Error "<<'\n';
     if(!pTexture11.loadFromFile("arrow left.png"))
         std::cout<<"Error "<<'\n';
     if(!pTexture12.loadFromFile("arrow right.png"))
         std::cout<<"Error "<<'\n';
     if(!pTexture6.loadFromFile("arrow right.png"))
         std::cout<<"Error "<<'\n';
     if(!B[3].texture_buton.loadFromFile("button1.png"))
         std::cout<<"Error "<<'\n';
     if(!pTexture8[1].loadFromFile("mute.png"))
            std::cout<<"Error"<<'\n';
      if(!pTexture8[2].loadFromFile("play.png"))
            std::cout<<"Error"<<'\n';
     if(!pTexture9.loadFromFile("carpet.png"))
         std::cout<<"Error "<<'\n';
     help_text.setTexture(help_text_textura);
     help.setTexture(help_textura);
     help.setPosition(help.getLocalBounds().width/4,help.getLocalBounds().height/4);
     help_text.setPosition(help.getPosition().x+help.getLocalBounds().width-20,help.getPosition().y+help.getLocalBounds().height);
     lemn.setTexture(pTexture9);
     audio[1].setTexture(pTexture8[1]);
     audio[2].setTexture(pTexture8[2]);
     Background.setTexture(pTexture);
     Background1.setTexture(pTexture1);
     B[1].buton.setTexture(B[1].texture_buton); B[1].buton.setPosition(380,350);
     B[2].buton.setTexture(B[2].texture_buton); B[2].buton.setPosition(380,450);
     B[3].buton.setTexture(B[3].texture_buton); B[3].buton.setPosition(380,550);
     titlu.setTexture(pTexture4);
     arrow_left.setTexture(pTexture5); arrow_left.setColor(sf::Color::Green);
     arrow_right.setTexture(pTexture6); arrow_right.setColor(sf::Color::Green);
     audio[1].setPosition(screenDimensions.x-audio[1].getLocalBounds().width,0);
     audio[2].setPosition(screenDimensions.x-audio[2].getLocalBounds().width,0);
     arrow_left.setPosition(screenDimensions.x/2-220,screenDimensions.y/2-10);
     arrow_right.setPosition(screenDimensions.x/2-25,screenDimensions.y/2-10);
     titlu.setPosition(screenDimensions.x/2-230,0);
     arrow_left_1.setTexture(pTexture11);
     arrow_right_1.setTexture(pTexture12);
     initializare_patrate();
     sf::Font font;
     if(!font.loadFromFile("orbitron-medium.otf"))
        std::cout<<"Can't find the font file"<<'\n';
     sf::String viteza="10";
     sf::Text textv(viteza,font,30);
     textv.setColor(sf::Color::Red);
     textv.setPosition(screenDimensions.x/2-textv.getLocalBounds().width/2,200);
     arrow_left_1.setPosition(textv.getPosition().x-arrow_left_1.getLocalBounds().width-10,200);
     arrow_right_1.setPosition(textv.getPosition().x+textv.getLocalBounds().width+15,200);
     arrow_left_1.setColor(sf::Color::Green);  arrow_right_1.setColor(sf::Color::Green);
     sf::String inapoi="Inapoi";
     sf::Text text3(inapoi,font,30);
     text3.setColor(sf::Color::Red);
     text3.setPosition(10,screenDimensions.y-text3.getLocalBounds().height-10);

     sf::String felicitari[6];
     felicitari[1]="Felicitari!"; felicitari[2]="Ai obtinut un punctaj de:";felicitari[3]="Numarul tau de mutari/ideal:"; felicitari[4]="Iesire"; felicitari[5]="Gata!";
     sf::Text text7[6];
     text7[1].setString(felicitari[1]); text7[1].setFont(font); text7[1].setCharacterSize(30); text7[1].setPosition(screenDimensions.x/2-text7[1].getLocalBounds().width/2,100); text7[1].setColor(sf::Color::Red);
     text7[3].setString(felicitari[3]); text7[3].setFont(font); text7[3].setCharacterSize(30); text7[3].setPosition(screenDimensions.x/2-text7[3].getLocalBounds().width/2,200); text7[3].setColor(sf::Color::Red);
     text7[2].setString(felicitari[2]); text7[2].setFont(font); text7[2].setCharacterSize(30); text7[2].setPosition(screenDimensions.x/2-text7[2].getLocalBounds().width/2,150); text7[2].setColor(sf::Color::Red);
     text7[4].setString(felicitari[4]); text7[4].setFont(font); text7[4].setCharacterSize(30); text7[4].setPosition(screenDimensions.x/2-text7[4].getLocalBounds().width/2,250); text7[4].setColor(sf::Color::Red);
     text7[5].setString(felicitari[5]); text7[5].setFont(font); text7[5].setCharacterSize(30); text7[5].setPosition(screenDimensions.x/2+5-text7[4].getLocalBounds().width/2,100); text7[5].setColor(sf::Color::Red);

     sf::String piese="Introdu numarul de piese:";
     sf::Text text4(piese,font,30);
     text4.setPosition(screenDimensions.x/2-300,screenDimensions.y/2-50);
     text4.setColor(sf::Color::Red);

     sf::String mod="Mod:";
     sf::Text text5(mod,font,30);
     text5.setPosition(screenDimensions.x/2-300,screenDimensions.y/2-10);
     text5.setColor(sf::Color::Red);

     sf::String restart="Restart";
     sf::Text text_restart(restart,font,30);
     text_restart.setPosition(screenDimensions.x-text_restart.getLocalBounds().width,screenDimensions.y-text_restart.getLocalBounds().height-20);
     text_restart.setColor(sf::Color::Red);


     sf::String alege="Alege-ti tema";
     sf::Text text10(alege,font,30);
     text10.setPosition(screenDimensions.x/2-text10.getLocalBounds().width/2,T[5].t_resize.getPosition().y+T[5].t_resize.getLocalBounds().height+20);
     text10.setColor(sf::Color::Red);

     sf::String choose[3];
     choose[1]="Automat"; choose[2]="Manual";
     sf::Text text6[3];
     text6[1].setFont(font); text6[1].setString(choose[1]); text6[1].setCharacterSize(30); text6[1].setPosition(screenDimensions.x/2-180,screenDimensions.y/2-10); text6[1].setColor(sf::Color(51,102,0));
     text6[2].setFont(font); text6[2].setString(choose[2]); text6[2].setCharacterSize(30); text6[2].setPosition(screenDimensions.x/2-180,screenDimensions.y/2-10); text6[2].setColor(sf::Color(51,102,0));

     sf::String enter="Apasa Enter pentru a incepe!";
     sf::Text text8(enter,font,30);
     text8.setPosition(screenDimensions.x/2-text8.getLocalBounds().width/2,screenDimensions.y/2+100);
     text8.setColor(sf::Color::Red);

     sf::String Despre[10];
     Despre[1]="Obiectivul jocului consta in a muta un set de discuri de pe tija din stanga";
     Despre[2]="pe cea mai din dreapta in cat mai putine mutari. Nu este permis ca un disc";
     Despre[3]="mare sa se afle peste unul mic. ";
     Despre[4]="In modul manual, mutarea pieselor se va face cu ajutorul mouse-ului, ";
     Despre[5]="tinand apasat pe click stanga.";
     Despre[6]="In modul automat, poti seta in timp real cu ce viteza vrei sa vezi piesele ";
     Despre[7]="miscandu-se. Vitezele sunt numerotate de la 1 la 20, unde 1 este viteza";
     Despre[8]="cea mai mare, iar 20 este viteza cea mai mica.";
     sf::Text text9[10];
     text9[1].setFont(font); text9[1].setString(Despre[1]); text9[1].setCharacterSize(25); text9[1].setPosition(10,titlu.getLocalBounds().height+10); text9[1].setColor(sf::Color::Red);
     text9[2].setFont(font); text9[2].setString(Despre[2]); text9[2].setCharacterSize(25); text9[2].setPosition(10,text9[1].getPosition().y+40); text9[2].setColor(sf::Color::Red);
     text9[3].setFont(font); text9[3].setString(Despre[3]); text9[3].setCharacterSize(25); text9[3].setPosition(10,text9[2].getPosition().y+40); text9[3].setColor(sf::Color::Red);
     text9[4].setFont(font); text9[4].setString(Despre[4]); text9[4].setCharacterSize(25); text9[4].setPosition(10,text9[3].getPosition().y+40); text9[4].setColor(sf::Color::Red);
     text9[5].setFont(font); text9[5].setString(Despre[5]); text9[5].setCharacterSize(25); text9[5].setPosition(10,text9[4].getPosition().y+40); text9[5].setColor(sf::Color::Red);
     text9[6].setFont(font); text9[6].setString(Despre[6]); text9[6].setCharacterSize(25); text9[6].setPosition(10,text9[5].getPosition().y+40); text9[6].setColor(sf::Color::Red);
     text9[7].setFont(font); text9[7].setString(Despre[7]); text9[7].setCharacterSize(25); text9[7].setPosition(10,text9[6].getPosition().y+40); text9[7].setColor(sf::Color::Red);
     text9[8].setFont(font); text9[8].setString(Despre[8]); text9[8].setCharacterSize(25); text9[8].setPosition(10,text9[7].getPosition().y+40); text9[8].setColor(sf::Color::Red);
     text9[9].setFont(font); text9[9].setString(Despre[9]); text9[9].setCharacterSize(25); text9[9].setPosition(10,text9[8].getPosition().y+40); text9[9].setColor(sf::Color::Red);
     int nr=0,k=1,cntr,vf1=-1,vf2=-1,vf3=-1,cntr1=0,cant=1,p,cntr2=0;


    bool joc=false,joc1=false,joc2=false,ok=false,ok1=false,ok2=false,ok3=false,ok4=false,despre=false,okpos=false;
    music.play();
     while(Window.isOpen())
     {
         sf::Event Event;
         while(Window.pollEvent(Event))
         {
             switch(Event.type)
            {

                case sf::Event::Closed:
                    Window.close();
                    break;
                case sf::Event::MouseMoved:
                    if(joc==false && despre==false )  ///daca misc mouse-ul si sunt in primul menu
                {

                    for(int i=1;i<=3;i++) ///in acest for verific pe ce buton se afla mouse-ul ca sa vad daca voi misca butonul in sus sau nu
                        if(verifbuton[i]==false && Event.mouseMove.x>=B[i].buton.getPosition().x && Event.mouseMove.x<=B[i].buton.getPosition().x+B[i].buton.getLocalBounds().width && Event.mouseMove.y>=B[i].buton.getPosition().y && Event.mouseMove.y<=B[i].buton.getPosition().y+B[i].buton.getLocalBounds().height)
                    {
                        verifbuton[i]=true;
                        B[i].buton.setPosition(B[i].buton.getPosition().x-10,B[i].buton.getPosition().y-10);
                        break;
                    }
                    else
                        if(verifbuton[i]==true && !(Event.mouseMove.x>=B[i].buton.getPosition().x && Event.mouseMove.x<=B[i].buton.getPosition().x+B[i].buton.getLocalBounds().width && Event.mouseMove.y>=B[i].buton.getPosition().y && Event.mouseMove.y<=B[i].buton.getPosition().y+B[i].buton.getLocalBounds().height))
                    {
                        verifbuton[i]=false;
                        B[i].buton.setPosition(B[i].buton.getPosition().x+10,B[i].buton.getPosition().y+10);
                    }

                }
                else
                {
                    if(joc==true && joc1==false)  ///daca suntem in cel de-al doilea meniu
                    {


                        if(Event.mouseMove.x>=280 && Event.mouseMove.x<=310 && Event.mouseMove.y>=390 && Event.mouseMove.y<=420) ///daca mouse-ul e pe sageata din stanga
                          arrow_left.setColor(sf::Color::Red); ///fac sageata rosie
                        else ///daca nu
                        {
                            arrow_left.setColor(sf::Color::Green); ///o fac inapoi verde
                            if(Event.mouseMove.x>=445 && Event.mouseMove.x<=505 && Event.mouseMove.y>=390 && Event.mouseMove.y<=420) ///daca mouse-ul e pe sageata din dreapta
                                arrow_right.setColor(sf::Color::Red); ///fac aceeasi chestie
                            else
                                arrow_right.setColor(sf::Color::Green);

                        }

                    }
                    else
                        if(joc==true && joc1==true && joc2==false) ///daca suntem in cel de-al doilea meniu cu "mapele"
                    {
                        for(int i=1;i<=6;i++) ///in acest for trec prin cele 6 mape si verific daca mouse-ul e pe unul din cele 6 mape prin conditia kilometrica de mai jos
                            {
                        if(verif[i]==false && Event.mouseMove.x>=T[i].t_resize.getPosition().x && Event.mouseMove.x<=T[i].t_resize.getPosition().x+T[i].t_resize.getLocalBounds().width && Event.mouseMove.y>=T[i].t_resize.getPosition().y && Event.mouseMove.y<=T[i].t_resize.getPosition().y +T[i].t_resize.getLocalBounds().height)
                             {
                                T[i].t_resize.setPosition(T[i].t_resize.getPosition().x-10,T[i].t_resize.getPosition().y-10); ///daca se respecta conditia ii setez noua pozitie
                                verif[i]=true; ///si marchez intr-un vector de tip bool ca am facut asta ca sa nu se pozitioneze si mai sus
                                break; ///si ies din parcurgere

                             }
                             else ///daca nu, verific daca mapa de indice i a fost deja setata cu o noua pozitie si intreb daca mouse-ul nu mai e prezent in "interiorul" acelei mape
                                if(verif[i]==true && !(Event.mouseMove.x>=T[i].t_resize.getPosition().x && Event.mouseMove.x<=T[i].t_resize.getPosition().x+T[i].t_resize.getLocalBounds().width && Event.mouseMove.y>=T[i].t_resize.getPosition().y && Event.mouseMove.y<=T[i].t_resize.getPosition().y +T[i].t_resize.getLocalBounds().height))
                             {
                             T[i].t_resize.setPosition(T[i].t_resize.getPosition().x+10,T[i].t_resize.getPosition().y+10); ///daca se respecta conditia pun pe pozitia initiala
                            verif[i]=false; ///si marchez inapoi pe false
                             }
                            }
                    }
                    else
                        if(joc==true && joc1==true && joc2==true && k==1)
                    {
                        if(Event.mouseMove.x>=arrow_left_1.getPosition().x && Event.mouseMove.x<=arrow_left_1.getPosition().x+arrow_left_1.getLocalBounds().width &&Event.mouseMove.y>=arrow_left_1.getPosition().y && Event.mouseMove.y<=arrow_left_1.getPosition().y+arrow_left_1.getLocalBounds().height)
                            arrow_left_1.setColor(sf::Color::Red);
                        else
                        {
                            arrow_left_1.setColor(sf::Color::Green);
                            if(Event.mouseMove.x>=arrow_right_1.getPosition().x && Event.mouseMove.x<=arrow_right_1.getPosition().x+arrow_right_1.getLocalBounds().width &&Event.mouseMove.y>=arrow_right_1.getPosition().y && Event.mouseMove.y<=arrow_right_1.getPosition().y+arrow_right_1.getLocalBounds().height)
                                arrow_right_1.setColor(sf::Color::Red);
                            else
                                arrow_right_1.setColor(sf::Color::Green);
                        }
                    }
                    else
                        if(joc==true && joc1==true && joc2==true  && k==2)
                    {
                        if(Event.mouseMove.x>=text_restart.getPosition().x && Event.mouseMove.x<=text_restart.getPosition().x+text_restart.getLocalBounds().width && Event.mouseMove.y>=text_restart.getPosition().y && Event.mouseMove.y<=text_restart.getPosition().y+text_restart.getLocalBounds().height )
                            text_restart.setColor(sf::Color::Black);
                        else
                            text_restart.setColor(sf::Color::Red);

                    }
                }
                break;
                case sf::Event::TextEntered: ///daca se introduce de la tastatura numarul de piese
                    if(Event.text.unicode>=49 && Event.text.unicode<=56 && joc==true && piese.getSize()==25) ///daca numarul de piese e intre 1 si 8
                        {
                        piese+=(char)Event.text.unicode; ///atunci actualizez string-ul
                        nr=Event.text.unicode-'0'; ///si retin numarul de patrate pe care-l voi avea de desenat
                        vf1=nr-1; ///retin de asemenea si in vf1 care reprezinta numarul de piese de pe prima tija la inceputul jocului, evident, va suferi modificari pe parcursul jocului
                        S[1].vf=nr-1; ///retin valoarea in S[1] pentru modul automat al jocului

                        }
                    else
                        if(Event.text.unicode==8 && piese.getSize()>25 && joc==true) ///daca apas pe Backspace
                           piese.erase(piese.getSize()-1,piese.getSize()); ///sterg ce am introdus
                break;
                case sf::Event::KeyPressed: ///daca apas pe o tasta
                    if(Event.key.code==sf::Keyboard::Return && piese.getSize()==26) ///si este enter
                        joc1=true; ///putem incepe sa alegem una din mape
                break;
                case sf::Event::MouseButtonPressed: ///daca am dat click
                    if((joc==true || joc==false) && joc2==false ) ///daca sunt in primul meniu, al doilea sau al treilea
                        {
                        if(Event.mouseButton.button==sf::Mouse::Left && joc==true && joc1==false) ///daca sunt in cel de-al doilea meniu si click stanga e apasat pe una dintre cele 2 sageti
                            if( Event.mouseButton.x>=280 && Event.mouseButton.x<=310 && Event.mouseButton.y>=390 && Event.mouseButton.y<=420 || Event.mouseButton.x>=475 && Event.mouseButton.x<=505 && Event.mouseButton.y>=390 && Event.mouseButton.y<=420)
                            {
                            k=3-k; ///schimb modul jocului ce va afisat (din automat se va trece in manual sau invers)
                            continue; ///ies din aceasta secventa de if ca nu ma mai intereseaza ce este mai jos
                            }
                        if(Event.mouseButton.button==sf::Mouse::Left && joc==true || joc==false) ///daca apas click stanga si sunt in unul din cele trei meniuri
                           {
                            if( Event.mouseButton.x>=960 && Event.mouseButton.x<=1000 && Event.mouseButton.y>=0 && Event.mouseButton.y<=50) ///daca apas pe iconita de sunet
                              {
                                a=3-a; ///schimb din audio in mute sau invers
                                if(a==1) music.pause();
                                else music.play();

                              }
                            else
                            if(joc1==true && joc2==false) ///daca sunt in cel de-al doilea meniu
                            for(int i=1;i<=6;i++) ///si,parcurgand cele 6 mape,verificam daca una dintre ele este apasata in conditia kilometrica de mai jos
                            {
                             if(Event.mouseButton.x>=T[i].t_resize.getPosition().x && Event.mouseButton.x<=T[i].t_resize.getPosition().x+T[i].t_resize.getLocalBounds().width && Event.mouseButton.y>=T[i].t_resize.getPosition().y && Event.mouseButton.y<=T[i].t_resize.getPosition().y+T[i].t_resize.getLocalBounds().height)
                             {
                                 joc2=true; ///daca se respecta conditia inseamna ca putem trece la joc(fie el manual sau automat)
                                 ind=i; ///retin indicele mapei ca sa setez dupa aceea ce textura voi alege pentru piese ca sa arate mai smecher
                                 if(ind>=2) ///daca nu am ales prima mapa, care nu are texturi pentru piese
                                    for(int j=0;j<=vf1;j++) ///setez la fiecare patrat textura corespunzatoare mapei
                                 {
                                    s1[j].setTexture(&T[ind].textura);
                                    S[1].s[j].setTexture(&T[ind].textura);
                                 }
                                 break;

                             }
                            }
                           }
                        }
                        else
                             {
                                if(Event.mouseButton.button==sf::Mouse::Left && joc==true && joc1==true && joc2==true && k==1 && xx<=cntrM && Event.mouseButton.x>=arrow_left_1.getPosition().x && Event.mouseButton.x<=arrow_left_1.getPosition().x+arrow_left_1.getLocalBounds().width &&Event.mouseButton.y>=arrow_left_1.getPosition().y && Event.mouseButton.y<=arrow_left_1.getPosition().y+arrow_left_1.getLocalBounds().height )
                             {
                             indtime--;
                             if(indtime<1) indtime=1;
                             viteza[0]=(char)(indtime/10+'0');
                             viteza[1]=(char)(indtime%10+'0');
                             textv.setString(viteza);
                             }
                             else
                             if(Event.mouseButton.button==sf::Mouse::Left && joc==true && joc1==true && joc2==true && k==1 && xx<=cntrM && Event.mouseButton.x>=arrow_right_1.getPosition().x && Event.mouseButton.x<=arrow_right_1.getPosition().x+arrow_right_1.getLocalBounds().width &&Event.mouseButton.y>=arrow_right_1.getPosition().y && Event.mouseButton.y<=arrow_right_1.getPosition().y+arrow_right_1.getLocalBounds().height)
                             {
                             indtime++;
                             if(indtime>20) indtime=20;
                             viteza[0]=(char)(indtime/10+'0');
                             viteza[1]=(char)(indtime%10+'0');
                             textv.setString(viteza);
                             }
                             }
                        break;
            }
        }
         text4.setString(piese);
        sf::Vector2i mousePosition=sf::Mouse::getPosition(Window);
        sf::Vector2f saize;
       frameCounter1+=frameSpeed1*clock1.restart().asSeconds();
        if(frameCounter1>=10)
        {
            frameCounter1=0;
            cloud.move(1,0);
            if(cloud.getPosition().x>1000)
                cloud.setPosition(0,cloud.getPosition().y);
        }


        saize=text7[4].getPosition();
        if(vf3==nr-1  || k==1 && joc1==true && joc2==true ) ///daca s-au terminat de pus piesele in modul automat  atunci voi seta culoarea textului "Gata" pe culoarea rosu sau negru in functie de pozitia mouse-ului
            {
            if(mousePosition.x>=saize.x && mousePosition.x<=saize.x+text7[4].getLocalBounds().width && mousePosition.y>=saize.y && mousePosition.y<=saize.y+text7[4].getLocalBounds().height)
                text7[4].setColor(sf::Color::Black);
            else
                text7[4].setColor(sf::Color::Red);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePosition.x>=saize.x && mousePosition.x<=saize.x+text7[4].getLocalBounds().width && mousePosition.y>=saize.y && mousePosition.y<=saize.y+text7[4].getLocalBounds().height )
                Window.close();
            }
        if(joc==false && despre==true || joc==true && joc1==false || joc==true && joc1==true && joc2==false || joc==true && joc1==true && joc2==true)
            if(mousePosition.x>=text3.getPosition().x && mousePosition.x<=text3.getPosition().x+text3.getLocalBounds().width && mousePosition.y>=text3.getPosition().y && mousePosition.y<=text3.getPosition().y+text3.getLocalBounds().height)
              text3.setColor(sf::Color::Black);
            else
                text3.setColor(sf::Color::Red);
        if(joc==false && despre==false) ///daca sunt in primul meniu si apas pe butonul "Despre"
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePosition.x>=B[2].buton.getPosition().x  && mousePosition.x<=B[2].buton.getPosition().x+B[2].buton.getLocalBounds().width && mousePosition.y>=B[2].buton.getPosition().y && mousePosition.y<=B[2].buton.getPosition().y+B[2].buton.getLocalBounds().height)
            {
            despre=true; ///atunci voi intra in meniul "despre"
            if(verifbuton[2]==true)
                B[2].buton.setPosition(B[2].buton.getPosition().x+10,B[2].buton.getPosition().y+10),verifbuton[2]=false;
            }
        if(joc==false && despre==false) ///daca sunt in primul meniu si apas pe butonul "Joaca"
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePosition.x>=B[1].buton.getPosition().x && mousePosition.x<=B[1].buton.getPosition().x+B[1].buton.getLocalBounds().width && mousePosition.y>=B[1].buton.getPosition().y && mousePosition.y<=B[1].buton.getPosition().y+B[1].buton.getLocalBounds().height)
             {
             joc=true; ///intru in cel de-al doilea meniu
             if(verifbuton[1]==true)
                B[1].buton.setPosition(B[1].buton.getPosition().x+10,B[1].buton.getPosition().y+10),verifbuton[1]=false;

             }
        else ///daca apas pe Iesire
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePosition.x>=B[3].buton.getPosition().x && mousePosition.x<=B[3].buton.getPosition().x+B[3].buton.getLocalBounds().width && mousePosition.y>=B[3].buton.getPosition().y && mousePosition.y<=B[3].buton.getPosition().y+B[3].buton.getLocalBounds().height && joc==false && despre==false)
              Window.close(); ///se inchide fereastra
        if(joc==true && despre==false && joc2==false &&  sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePosition.x>=10 && mousePosition.x<=110 && mousePosition.y>=765 && mousePosition.y<=795 ) ///daca apas pe Inapoi
            {
             if(joc1==true) ///daca sunt in cel de-al treilea meniu, cu mapele
                    joc1=false; ///ar trebui sa revin la al doilea meniu dar din motive nestiute revin la primul meniu :))))
             else
                joc=false;
            piese.erase(25,piese.getSize());
            }
        if(joc2==true && k==2 && ok1==false && ok2==false && ok3==false && sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePosition.x>=text_restart.getPosition().x && mousePosition.x<=text_restart.getPosition().x+text_restart.getLocalBounds().width && mousePosition.y>=text_restart.getPosition().y && mousePosition.y<=text_restart.getPosition().y+text_restart.getLocalBounds().height )
           {
               vf2=-1;vf3=-1; vf1=-1;
               initializare_patrate();
               cntr1=0;
               felicitari[2]="Ai obtinut un punctaj de:";
               felicitari[3]="Numarul tau de mutari/ideal:";
               ok=false;
               vf1=nr-1;
               if(ind>=2)
                for(int i=0;i<=vf1;i++)
                 s1[i].setTexture(&T[ind].textura);

           }
        if(joc2==true && ok1==false && ok2==false && ok3==false  && sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePosition.x>=10 && mousePosition.x<=110 && mousePosition.y>=765 && mousePosition.y<=795)
        {
            vf2=-1; vf3=-1; vf1=-1;
            S[1].vf=-1; S[2].vf=-1; S[3].vf=-1;
            initializare_patrate();
            cntr1=0;
            felicitari[2]="Ai obtinut un punctaj de:";
            felicitari[3]="Numarul tau de mutari/ideal:";
            ok=false;
            joc2=false;
            if(k==1)
                {
                ok4=false;
                cntrM=0;
                xx=-1;
                indtime=10;
                viteza[0]='1';
                viteza[1]='0';
                textv.setString(viteza);
                }
            if(a==2)
            music.play();
        }
        if(joc==false && despre==true && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&  mousePosition.x>=10 && mousePosition.x<=110 && mousePosition.y>=765 && mousePosition.y<=795) ///daca apas pe Inapoi si sunt in sectiunea "Despre"
        {
        despre=false; ///revin inapoi la meniul principal
        }
        if(joc1==true && joc2==true  && k==2 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && vf3!=nr-1) ///daca sunt in timpul jocului pe modul "Manual" si apas click stanga
                    {

                        sf::Vector2f position1;
                        sf::Vector2f position2;
                        sf::Vector2f position3;
                        sf::Vector2i mousePosition=sf::Mouse::getPosition(Window);
                        if(vf1>=0) position1=s1[vf1].getPosition();  ///extrag pozitia fiecarei piese din varful celor trei tije, daca exista piesa in varf
                        if(vf2>=0) position2=s2[vf2].getPosition();
                        if(vf3>=0) position3=s3[vf3].getPosition();
                        ///verific daca apas click pe piesa care se afla in unul din cele trei varfuri
                        if(vf1>=0 && mousePosition.x>=position1.x && mousePosition.x<=s1[vf1].getLocalBounds().width+position1.x && mousePosition.y>=position1.y && mousePosition.y<=position1.y+s1[vf1].getLocalBounds().height && ok2==false && ok3==false)
                             {
                            ok1=true;
                            if(okpos==false)
                            xa=mousePosition.x-position1.x,ya=mousePosition.y-position1.y,okpos=true;
                             }

                        if(vf2>=0 && mousePosition.x>=position2.x && mousePosition.x<=s2[vf2].getLocalBounds().width+position2.x && mousePosition.y>=position2.y && mousePosition.y<=position2.y+s2[vf2].getLocalBounds().height && ok1==false && ok3==false)
                            {
                            ok2=true;
                            if(okpos==false)
                                xa=mousePosition.x-position2.x,ya=mousePosition.y-position2.y,okpos=true;
                            }
                        if(vf3>=0 && mousePosition.x>=position3.x && mousePosition.x<=s3[vf3].getLocalBounds().width+position3.x && mousePosition.y>=position3.y && mousePosition.y<=position3.y+s3[vf3].getLocalBounds().height && ok1==false && ok2==false)
                            {
                            ok3=true;
                            if(okpos==false)
                                xa=mousePosition.x-position3.x,ya=mousePosition.y-position3.y,okpos=true;

                            }
                        if(ok1 && ok2==false && ok3==false) ///daca am apasat click pe o piesa
                         {
                         if(mousePosition.x-xa<0) mousePosition.x=xa;
                         if(mousePosition.x-xa+s1[vf1].getLocalBounds().width>1000) mousePosition.x=1000+xa-s1[vf1].getLocalBounds().width;
                         if(mousePosition.y-ya<0) mousePosition.y=ya;
                         if(mousePosition.y-ya+s1[vf1].getLocalBounds().height>800) mousePosition.y=800+ya-s1[vf1].getLocalBounds().height;
                         s1[vf1].setPosition(mousePosition.x-xa,mousePosition.y-ya);   ///incep sa o desenez pe pozitia de unde am dat click pe patrat
                         }
                        if(ok2 && ok1==false && ok3==false)
                            {
                         if(mousePosition.x-xa<0) mousePosition.x=xa;
                         if(mousePosition.x-xa+s2[vf2].getLocalBounds().width>1000) mousePosition.x=1000+xa-s2[vf2].getLocalBounds().width;
                         if(mousePosition.y-ya<0) mousePosition.y=ya;
                         if(mousePosition.y-ya+s2[vf2].getLocalBounds().height>800) mousePosition.y=800+ya-s2[vf2].getLocalBounds().height;
                            s2[vf2].setPosition(mousePosition.x-xa,mousePosition.y-ya);
                            }
                        if(ok3 && ok1==false && ok2==false)
                            {
                         if(mousePosition.x-xa<0) mousePosition.x=xa;
                         if(mousePosition.x-xa+s3[vf3].getLocalBounds().width>1000) mousePosition.x=1000+xa-s3[vf3].getLocalBounds().width;
                         if(mousePosition.y-ya<0) mousePosition.y=ya;
                         if(mousePosition.y-ya+s3[vf3].getLocalBounds().height>800) mousePosition.y=800+ya-s3[vf3].getLocalBounds().height;
                            s3[vf3].setPosition(mousePosition.x-xa,mousePosition.y-ya);
                            }
                    }
         if(joc1==true && joc2==true && k==2 && ok1==true && vf3!=nr-1) ///aici fac o serie de subcazuri in cazul in care am luat o piesa de pe prima tija
         {

                  if(!(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                                {
                                okpos=false;
                                if( s1[vf1].getPosition().x+s1[vf1].getLocalBounds().width/2>=330 && s1[vf1].getPosition().x+s1[vf1].getLocalBounds().width/2<=640 )
                                {
                                    if(vf2==-1 || s1[vf1].getLocalBounds().width<s2[vf2].getLocalBounds().width)
                                    {
                                    sound1.play();
                                    cntr1++;
                                    sf::Vector2f saize;
                                    s2[++vf2]=s1[vf1];
                                    vf1--;
                                    if(vf2==0)
                                    s2[vf2].setPosition((385+640)/2-s2[vf2].getLocalBounds().width/2,600);
                                    else
                                    {
                                        saize=s2[vf2-1].getPosition();
                                        s2[vf2].setPosition(((2*saize.x+s2[vf2-1].getLocalBounds().width)/2-s2[vf2].getLocalBounds().width/2),saize.y-40);
                                    }
                                    ok1=false;
                                    }
                                    else
                                        {
                                        sound.play();
                                        if(vf1==0)
                                          s1[vf1].setPosition((80+330)/2-s1[vf1].getLocalBounds().width/2,600);
                                        else
                                        {
                                        sf::Vector2f saize;
                                        saize=s1[vf1-1].getPosition();
                                        s1[vf1].setPosition(((2*saize.x+s1[vf1-1].getLocalBounds().width)/2-s1[vf1].getLocalBounds().width/2),saize.y-40);
                                        }
                                        ok1=false;
                                        }

                                }
                                else
                                    if(  s1[vf1].getPosition().x+s1[vf1].getLocalBounds().width/2<330)
                                {
                                    sound1.play();
                                    ok1=false;
                                    if(vf1==0)
                                        s1[vf1].setPosition((80+330)/2-s1[vf1].getLocalBounds().width/2,600);
                                    else
                                    {
                                    sf::Vector2f saize;
                                    saize=s1[vf1-1].getPosition();
                                    s1[vf1].setPosition(((2*saize.x+s1[vf1-1].getLocalBounds().width)/2-s1[vf1].getLocalBounds().width/2),saize.y-40);
                                    }
                                }
                                else
                                if(s1[vf1].getPosition().x+s1[vf1].getLocalBounds().width/2>640)
                                {

                                    ok1=false;
                                    if(vf3==-1 || s1[vf1].getLocalBounds().width<s3[vf3].getLocalBounds().width)
                                    {
                                    sound1.play();
                                    cntr1++;
                                    sf::Vector2f saize;
                                    s3[++vf3]=s1[vf1];
                                    vf1--;
                                    if(vf3==0)
                                        s3[vf3].setPosition(((680+940)/2-s3[vf3].getLocalBounds().width/2),600);
                                    else
                                    {
                                        saize=s3[vf3-1].getPosition();
                                        s3[vf3].setPosition(((2*saize.x+s3[vf3-1].getLocalBounds().width)/2-s3[vf3].getLocalBounds().width/2),saize.y-40);
                                    }
                                    }
                                    else
                                    {
                                        sound.play();
                                        if(vf1==0)
                                        s1[vf1].setPosition((80+330)/2-s1[vf1].getLocalBounds().width/2,600);
                                        else
                                        {
                                    sf::Vector2f saize;
                                    saize=s1[vf1-1].getPosition();
                                    s1[vf1].setPosition(((2*saize.x+s1[vf1-1].getLocalBounds().width)/2-s1[vf1].getLocalBounds().width/2),saize.y-40);
                                        }

                                    }
                                }
                                }
         }
         if(joc1==true && joc2==true  && k==2 && ok2==true && vf3!=nr-1)
         {
                            if(!(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                                 {
                                     okpos=false;
                                if(s2[vf2].getPosition().x+s2[vf2].getLocalBounds().width/2>=330 && s2[vf2].getPosition().x+s2[vf2].getLocalBounds().width/2<=640)
                            {
                               sound1.play();
                               ok2=false;
                                if(vf2==0)
                                    s2[vf2].setPosition((385+640)/2-s2[vf2].getLocalBounds().width/2,600);
                                else
                                {
                                    sf::Vector2f saize;
                                    saize=s2[vf2-1].getPosition();
                                    s2[vf2].setPosition((2*saize.x+s2[vf2-1].getLocalBounds().width)/2-s2[vf2].getLocalBounds().width/2,saize.y-40);
                                }
                            }
                            else
                                if(s2[vf2].getPosition().x+s2[vf2].getLocalBounds().width/2>640)
                            {
                                ok2=false;
                                if(vf3==-1 || s2[vf2].getLocalBounds().width<s3[vf3].getLocalBounds().width)
                                {
                                 sound1.play();
                                 cntr1++;
                                 s3[++vf3]=s2[vf2];
                                 vf2--;
                                 if(vf3==0)
                                    s3[vf3].setPosition(((680+940)/2-s3[vf3].getLocalBounds().width/2),600);
                                 else
                                 {
                                     sf::Vector2f saize;
                                     saize=s3[vf3-1].getPosition();
                                     s3[vf3].setPosition(((2*saize.x+s3[vf3-1].getLocalBounds().width)/2-s3[vf3].getLocalBounds().width/2),saize.y-40);
                                 }
                                }
                                else
                                {
                                    sound.play();
                                    if(vf2==0)
                                      s2[vf2].setPosition(((385+640)/2-s2[vf2].getLocalBounds().width/2),600);
                                    else
                                    {
                                    sf::Vector2f saize;
                                    saize=s2[vf2-1].getPosition();
                                    s2[vf2].setPosition(((2*saize.x+s2[vf2-1].getLocalBounds().width)/2-s2[vf2].getLocalBounds().width/2),saize.y-40);
                                    }

                                }
                            }
                            else
                                if(s2[vf2].getPosition().x+s2[vf2].getLocalBounds().width/2<330)
                            {
                                ok2=false;
                                if(vf1==-1 || s2[vf2].getLocalBounds().width<s1[vf1].getLocalBounds().width)
                                {
                                    sound1.play();
                                    s1[++vf1]=s2[vf2];
                                    cntr1++;
                                    vf2--;
                                    if(vf1==0)
                                        s1[vf1].setPosition((80+330)/2-s1[vf1].getLocalBounds().width/2,600);
                                    else
                                    {
                                        sf::Vector2f saize;
                                        saize=s1[vf1-1].getPosition();
                                        s1[vf1].setPosition(((2*saize.x+s1[vf1-1].getLocalBounds().width)/2 - s1[vf1].getLocalBounds().width/2),saize.y-40);

                                    }
                                }
                                else
                                {
                                     sound.play();
                                     if(vf2==0)
                                      s2[vf2].setPosition(((385+640)/2-s2[vf2].getLocalBounds().width/2),600);
                                    else
                                    {
                                    sf::Vector2f saize;
                                    saize=s2[vf2-1].getPosition();
                                    s2[vf2].setPosition(((2*saize.x+s2[vf2-1].getLocalBounds().width)/2-s2[vf2].getLocalBounds().width/2),saize.y-40);
                                    }

                                }

                            }
                                 }
         }
         if(joc1==true && joc2==true && k==2 && ok3==true && vf3!=nr-1)
         {
           if(!(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
              {
                  okpos=false;
                if(s3[vf3].getPosition().x+s3[vf3].getLocalBounds().width/2>640)
           {
               sound1.play();
               ok3=false;
               if(vf3==0)
                s3[vf3].setPosition(((680+940)/2-s3[vf3].getLocalBounds().width/2),600);
               else
               {
                   sf::Vector2f saize;
                   saize=s3[vf3-1].getPosition();
                   s3[vf3].setPosition(((2*saize.x+s3[vf3-1].getLocalBounds().width)/2-s3[vf3].getLocalBounds().width/2),saize.y-40);
               }
           }
           else
            if(s3[vf3].getPosition().x+s3[vf3].getLocalBounds().width/2>=330 && s3[vf3].getPosition().x+s3[vf3].getLocalBounds().width/2<=640)
           {
               ok3=false;
               if(vf2==-1 || s3[vf3].getLocalBounds().width<s2[vf2].getLocalBounds().width)
               {
                  sound1.play();
                  s2[++vf2]=s3[vf3];
                  cntr1++;
                  vf3--;
                  if(vf2==0)
                    s2[vf2].setPosition(((385+640)/2-s2[vf2].getLocalBounds().width/2),600);
                  else
                  {
                      sf::Vector2f saize;
                      saize=s2[vf2-1].getPosition();
                      s2[vf2].setPosition(((2*saize.x+s2[vf2-1].getLocalBounds().width)/2-s2[vf2].getLocalBounds().width/2),saize.y-40);
                  }
               }
               else
               {
                sound.play();
                if(vf3==0)
                  s3[vf3].setPosition(((680+940)/2-s3[vf3].getLocalBounds().width/2),600);
                else
                {
                    sf::Vector2f saize;
                    saize=s3[vf3-1].getPosition();
                    s3[vf3].setPosition(((2*saize.x+s3[vf3-1].getLocalBounds().width)/2-s3[vf3].getLocalBounds().width/2),saize.y-40);
                }
               }
           }
           else
            if(s3[vf3].getPosition().x+s3[vf3].getLocalBounds().width/2<330)
           {
               ok3=false;
               if(vf1==-1 || s3[vf3].getLocalBounds().width<s1[vf1].getLocalBounds().width)
               {
                   sound1.play();
                   s1[++vf1]=s3[vf3];
                   cntr1++;
                   vf3--;
                   if(vf1==0)
                   s1[vf1].setPosition((80+330)/2-s1[vf1].getLocalBounds().width/2,600);
                   else
                   {
                       sf::Vector2f saize;
                       saize=s1[vf1-1].getPosition();
                       s1[vf1].setPosition(((2*saize.x+s1[vf1-1].getLocalBounds().width)/2-s1[vf1].getLocalBounds().width/2),saize.y-40);
                   }

               }
               else
               {
                   sound.play();
                   if(vf3==0)
                   s3[vf3].setPosition(((680+940)/2-s3[vf3].getLocalBounds().width/2),600);
                   else
                   {
                    sf::Vector2f saize;
                    saize=s3[vf3-1].getPosition();
                    s3[vf3].setPosition(((2*saize.x+s3[vf3-1].getLocalBounds().width)/2-s3[vf3].getLocalBounds().width/2),saize.y-40);
                   }

               }
           }
              }

         }
       if(joc==true && joc1==true && joc2==true  && k==1 && xx<=cntrM)
       {
            music.pause();
            if(ok4==false)
            {
            ok4=true;
           Hanoi(nr,'A','B','C',ind);
           S[1].vf=-1; S[2].vf=-1; S[3].vf=-1;
           initializare_patrate();
           S[1].vf=nr-1;
           for(int i=0;i<=S[1].vf;i++)
            S[1].s[i].setTexture(&T[ind].textura);
            }
            Window.clear();
            Window.draw(T[ind].fundal);
            Window.draw(textv);
            Window.draw(arrow_left_1);
            Window.draw(arrow_right_1);
            Window.draw(text3);
            for(int i=1;i<=3;i++)
            for(int j=0;j<=S[i].vf;j++)
              Window.draw(S[i].s[j]);
            Window.display();
            frameCounter+=frameSpeed*clock.restart().asSeconds();
             if(frameCounter >=frameSpeed*((float)(timp[indtime]/10)))
             {
              frameCounter=0;
            xx++;
            if(xx<=cntrM && xx>=1)
            {
                 S[M[xx].m_sosire].s[++S[M[xx].m_sosire].vf]=S[M[xx].m_plecare].s[S[M[xx].m_plecare].vf];
                 S[M[xx].m_plecare].vf--;
                 S[M[xx].m_sosire].s[S[M[xx].m_sosire].vf].setPosition(M[xx].x,M[xx].y);
            }
             }

            //asteapta((float)timp[indtime]/10);

       }
       else
        if(joc==false && despre==false && joc1==false && joc2==false)
          {
        Window.clear();
        Window.draw(Background);
        Window.draw(cloud);
        Window.draw(titlu);
        for(int i=1;i<=3;i++)
        Window.draw(B[i].buton);
        Window.draw(audio[a]);
        Window.display();


        }
        else
            if(joc==false && despre==true && joc1==false && joc2==false)
        {
            Window.clear();
            Window.draw(Background);
            Window.draw(cloud);
            Window.draw(text3);
            Window.draw(titlu);
            for(int i=1;i<=9;i++)
                Window.draw(text9[i]);
            Window.draw(audio[a]);
            Window.display();


        }
        else
           if(joc==true && joc1==false &&  joc2==false)
          {
        Window.clear();
        Window.draw(Background);
        Window.draw(cloud);
        Window.draw(titlu);
        Window.draw(text3);
        Window.draw(text4);
        Window.draw(text5);
        Window.draw(text6[k]);
        Window.draw(text8);
        Window.draw(arrow_left);
        Window.draw(arrow_right);
        Window.draw(audio[a]);
        Window.display();
          }
        else if(joc==true && joc1==true && joc2==true  && k==2)
        {
            Window.clear();
            music.pause();
            Window.draw(T[ind].fundal);
            Window.draw(text3);
            Window.draw(text_restart);
            for(int i=0;i<=vf1;i++)
                Window.draw(s1[i]);
            for(int i=0;i<=vf2;i++)
                Window.draw(s2[i]);
            for(int i=0;i<=vf3;i++)
                Window.draw(s3[i]);
            if(vf3==nr-1)
                {

                cant=1;
                cntr2=0;
                int cntr3=0,cntr4=0;
                if(ok==false)
                 {
                    ok=true;
                    for(int i=1;i<=nr;i++ )
                    cant*=2;
                p=(cant-1)*100/cntr1;
                if(p==0)
                    v[++cntr2]=0;
                else
                while(p)
                    v[++cntr2]=p%10,p/=10;
                for(int i=cntr2;i>=1;--i)
                    felicitari[2]+=(char)(v[i]+'0');
                felicitari[2]+='%';
                while(cntr1)
                {
                    t[++cntr3]=cntr1%10;
                    cntr1/=10;
                }
                cant--;
                while(cant)
                {
                    ideal[++cntr4]=cant%10;
                    cant/=10;
                }
                for(int i=cntr3;i>=1;i--)
                    felicitari[3]+=(char)(t[i]+'0');
                felicitari[3]+='/';
                for(int i=cntr4;i>=1;i--)
                    felicitari[3]+=(char)(ideal[i]+'0');

                text7[2].setString(felicitari[2]);
                text7[3].setString(felicitari[3]);
                text7[2].setPosition(screenDimensions.x/2-text7[2].getLocalBounds().width/2,150);
                text7[3].setPosition(screenDimensions.x/2-text7[3].getLocalBounds().width/2,200);

                 }
                for(int i=1;i<=4;i++)
                    Window.draw(text7[i]);


                }
                Window.display();






        }
        else
            if(joc1==true  && joc2==true && xx>cntrM && k==1)
        {
            Window.clear();
            Window.draw(T[ind].fundal);
            for(int i=1;i<=3;i++)
                for(int j=0;j<=S[i].vf;j++)
                Window.draw(S[i].s[j]);
            Window.draw(text7[4]);
            Window.draw(text7[5]);
            Window.draw(text3);
            Window.display();


        }
        else
            if(joc1==true && joc2==false && joc==true)
        {
        Window.clear();
        Window.draw(Background);
        Window.draw(cloud);
        Window.draw(titlu);
        Window.draw(text3);
        Window.draw(audio[a]);
        for(int i=1;i<=6;i++)
            Window.draw(T[i].t_resize);
        Window.draw(text10);
        Window.display();
        }

    }



    return 0;
}

void mutari(int t_plecare, int t_sosire,int &cntrM)
{
    S[t_sosire].s[++S[t_sosire].vf]=S[t_plecare].s[S[t_plecare].vf];
    S[t_plecare].vf--;
    M[++cntrM].m_plecare=t_plecare;
    M[cntrM].m_sosire=t_sosire;
    if(S[t_sosire].vf==0)
    {
        if(t_sosire==1)
         {
            S[t_sosire].s[S[t_sosire].vf].setPosition((80+330)/2-S[t_sosire].s[S[t_sosire].vf].getLocalBounds().width/2,600);
            M[cntrM].x=S[t_sosire].s[S[t_sosire].vf].getPosition().x;
            M[cntrM].y=S[t_sosire].s[S[t_sosire].vf].getPosition().y;
         }
        else if(t_sosire==2)
         {
        S[t_sosire].s[S[t_sosire].vf].setPosition((385+640)/2-S[t_sosire].s[S[t_sosire].vf].getLocalBounds().width/2,600);
        M[cntrM].x=S[t_sosire].s[S[t_sosire].vf].getPosition().x;
        M[cntrM].y=S[t_sosire].s[S[t_sosire].vf].getPosition().y;
         }
         else
         {
            S[t_sosire].s[S[t_sosire].vf].setPosition((680+940)/2-S[t_sosire].s[S[t_sosire].vf].getLocalBounds().width/2,600);
           M[cntrM].x=S[t_sosire].s[S[t_sosire].vf].getPosition().x;
           M[cntrM].y=S[t_sosire].s[S[t_sosire].vf].getPosition().y;
         }



    }
    else
    {
        sf::Vector2f saize;
        saize=S[t_sosire].s[S[t_sosire].vf-1].getPosition();
        S[t_sosire].s[S[t_sosire].vf].setPosition((2*saize.x+S[t_sosire].s[S[t_sosire].vf-1].getLocalBounds().width)/2-S[t_sosire].s[S[t_sosire].vf].getLocalBounds().width/2,saize.y-40);
        M[cntrM].x=S[t_sosire].s[S[t_sosire].vf].getPosition().x;
        M[cntrM].y=S[t_sosire].s[S[t_sosire].vf].getPosition().y;
    }
}
void Hanoi(int m, char a, char b, char c, int ind)
{

  int t_plecare,t_sosire;
  if(m == 1)
{
    t_plecare=a-'A'+1;
    t_sosire=c-'A'+1;
    mutari(t_plecare,t_sosire,cntrM);
  }
  else
  {
    Hanoi(m-1, a,c,b,ind);
    t_plecare=a-'A'+1;
    t_sosire=c-'A'+1;
    mutari(t_plecare,t_sosire,cntrM);
    Hanoi(m-1,b,a,c,ind);
  }
}


