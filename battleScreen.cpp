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
    // MNTexture.loadFromFile("Sprites/monster_battle_sprites.png");
    // if(!MNTexture.loadFromFile("Sprites/monster_battle_sprites.png"))
    // {
    //     exit(1);
    // }
    // MonsterN.setTexture(MNTexture);

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