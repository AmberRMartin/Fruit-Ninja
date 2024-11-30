#include "battleScreen.h"

BattleScreen::BattleScreen()
{

//Background and text
    backTexture.loadFromFile("Sprites/Battle_screen_background.png");
    if(!backTexture.loadFromFile("Sprites/Battle_screen_background.png"))
    {
        exit(1);
    }
    Background.setTexture(backTexture);
    Background.setPosition(200,0);

    font.loadFromFile("Minecraftia-Regular.ttf");
    PHpTxt.setFont(font);
    PManaTxt.setFont(font);

    PHpTxt.setString("HP: 20/20");
    PManaTxt.setString("Mana: ?/?");

    PHpTxt.setScale(0.8, 0.8);
    PManaTxt.setScale(0.8,0.8);
    
   PHpTxt.setPosition(535,365);
   PManaTxt.setPosition(535,415);

   PHpTxt.setFillColor(sf::Color::Black);
   PManaTxt.setFillColor(sf::Color::Black);


//Buttons

    Button Temp1("Attack", {320,50},{194,55});
    Button Temp2("Skill", {570,50},{194,55});
    Attack = Temp1;
    Skill = Temp2;
    Attack.fixFiles();
    Skill.fixFiles();

//player stuff
    Players.loadFromFile("Sprites/player_battle_sprites.png");
    if(!Players.loadFromFile("Sprites/player_battle_sprites.png"))
    {
        exit(1);
    }

    PlayerN.setTexture(Players);
    PlayerA.setTexture(Players);
    PlayerD.setTexture(Players);
    PlayerN.setTextureRect(sf::IntRect({0,0}, {146,146}));
    PlayerA.setTextureRect(sf::IntRect({151,0},{146,146}));
    PlayerD.setTextureRect(sf::IntRect({304,0},{146,146}));

    PlayerN.setOrigin(73,73);
    PlayerN.setPosition({450, 415});
    PlayerA.setOrigin(73,73);
    PlayerA.setPosition({450, 415});
    PlayerD.setOrigin(73,73);
    PlayerD.setPosition({450, 415});
    

//Monster stuff
    Monsters.loadFromFile("Sprites/monster_battle_sprites.png");
    if(!Monsters.loadFromFile("Sprites/monster_battle_sprites.png"))
    {
        exit(1);
    }
//default monster is cherry
    MonsterN.setTexture(Monsters);
    MonsterA.setTexture(Monsters);
    MonsterD.setTexture(Monsters);

    MonsterN.setTextureRect(sf::IntRect({0,0},{292,192}));
    MonsterA.setTextureRect(sf::IntRect({0,297},{292,192}));
    MonsterD.setTextureRect(sf::IntRect({0,573},{292,192}));

    MonsterN.setOrigin({146,96});
    MonsterA.setOrigin({146,96});
    MonsterD.setOrigin({146,96});

    MonsterN.setPosition({450, 200});
    MonsterA.setPosition({450, 200});
    MonsterD.setPosition({450,200});

//Misc;
    SkillMenu = false;
    DrawAttacking = false;
    DrawDamaged = false;

}

void BattleScreen::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(Background);
    if(SkillMenu == false)
    {
        target.draw(PlayerN);
        target.draw(Attack);
        target.draw(Skill);
        target.draw(MonsterN);
        target.draw(PHpTxt);
        target.draw(PManaTxt);
    }
    else if (SkillMenu == true)
    {
//All skill buttons go here
    }
    else if(DrawAttacking == true)
    {
        target.draw(PlayerA);
    }
    else if(DrawDamaged == true)
    {
        target.draw(PlayerD);
    }
}

void BattleScreen::update(sf::Event& e, sf::RenderWindow& window)
{

}