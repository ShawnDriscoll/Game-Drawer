
# Python 2.5.4 code used in video from http://www.youtube.com/watch?v=gTT6TtpDBLk

from diceroll import roll

char_name = ['STR', 'DEX', 'END', 'INT', 'EDU', 'SOC', 'PSI']
char_dms = [-3, -2, -2, -1, -1, -1, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3]
char = [0,0,0,0,0,0,0]
char_dm = [0,0,0,0,0,0,0]

STR = 0
DEX = 1
END = 2
INT = 3
EDU = 4
SOC = 5
PSI = 6

gun_combat = 0
science = 1
engineering = 2
pilot = 3
medic = 4
computers = 5
stealth = 6
survival = 7
melee = 8

skill = []
for i in range(9):
    skill.append(-3)
    
def update_dm(char_dm):
    for i in range(7):
        char_dm[i] = char_dms[char[i]]
        
def test(sk, cm, diff):
    natural = roll('2D6')
    effect = natural +sk + cm + diff - 8
    return effect, natural
        
def start():
    for i in range(len(char_name)):
        char[i] = roll('2D6')
        
    update_dm(char_dm)
        
    for i in range(len(char_name)):
        print '%s: %2d  DM %2d' % (char_name[i], char[i], char_dm[i])
        
    skill[gun_combat] = 1
    skill[melee] = 2
    skill[computers] = 4
    skill[pilot] = 0
    
# Gun Combat test
    print '--Gun Combat skill test--'
    effect, natural = test(skill[gun_combat], char_dm[DEX], -2)
    print 'Effect:', effect
    print 'Natural roll:', natural
    
# Stealth test
    print '--Stealth skill test--'
    effect, natural = test(skill[stealth], char_dm[DEX], 2)
    print 'Effect:', effect
    print 'Natural roll:', natural
    
# Pilot test
    print '--Pilot skill test--'
    effect, natural = test(skill[pilot], char_dm[DEX], 6)
    print 'Effect:', effect
    print 'Natural roll:', natural    


if __name__ == '__main__':
    start()