typedef struct_wallet{
    int coin;
    int bill;
} Wallet;   //구조체

int TakeOut(Wallet* pw, int coin, int bill) //구조체 관련 연산

int main(){
    Wallet m_Wallet;
    int ret = TakeOut(&m_Wallet, 2, 5);
}
