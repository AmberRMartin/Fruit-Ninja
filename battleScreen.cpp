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

    Button Temp3("Heal",{450,360}, {294, 45});
    Button Temp4("Slice", {450,410}, {294, 45});
    Button Temp5("Return", {450, 460}, {294, 45});
    
    Heal = Temp3;
    SkillAtk = Temp4;
    ReturnSkill = Temp5;
    Heal.fixFiles();
    SkillAtk.fixFiles();
    ReturnSkill.fixFiles();

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
    target.draw(MonsterN);
    if(SkillMenu == false)
    {
        target.draw(PlayerN);
        target.draw(Attack);
        target.draw(Skill);
        target.draw(PHpTxt);
        target.draw(PManaTxt);
    }
    else if (SkillMenu == true)
    {
//All skill buttons go here
        target.draw(Heal);
        target.draw(SkillAtk);
        target.draw(ReturnSkill);
    }
}

void BattleScreen::update(sf::Event& e, sf::RenderWindow& window)
{
    if(Skill.clicked(e, window))
    {
        SkillMenu = true;
    }
    else if (ReturnSkill.clicked(e, window))
    {
        SkillMenu = false;
    }
}

void BattleScreen::updateStats(Stats &stats)
{
    std::string hp = std::to_string(stats.getMaxHP());
    PHpTxt.setString("HP: " + hp + "/" + hp);
//this is what I assume mana looks like. fix whenever we have that function
//only thing that needs edited is the max mana name function
    //std::string mana = std::to_string(stats.getMaxMana());
    //PManaTxt.setString("Mana: " + mana + "/" + mana);
}