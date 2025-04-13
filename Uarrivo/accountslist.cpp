#include "accountslist.h"

accountlist::accountlist()
{
    head = nullptr;
}

void accountlist:: insert(account a, personal_info p, wallet wal, creditCard c){
    node* newnode = new node;
    newnode->user = a;
    newnode->w = wal;
    newnode->credit = c;
    newnode->info = p;
    if(head == nullptr){
        head = newnode;
    }else{
        node* curr = head;
        while(curr->next){
            curr=curr->next;
        }
        curr->next = newnode;
    }
}

bool accountlist :: login(string pass, string em){
    node* curr = head;
    while(curr != nullptr){
        if(curr->user.allowlogin(pass,em) == true){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool accountlist ::usernameavailable(string email){
    node* curr = head;
    while(curr != nullptr){
        if(curr->user.getemail() == email){
            return false;
        }
        curr = curr->next;
    }
    return true;
}

account accountlist :: returnaccount(string user){
    node* curr = head;
    account null;
    while(curr != nullptr){
        if(curr->user.getemail() == user){
            return curr->user;
        }
        curr = curr->next;
    }
    return null;

}

personal_info accountlist::returninfo(string user){
    node* curr = head;
    personal_info null;
    while(curr != nullptr){
        if(curr->user.getemail() == user){
            return curr->info;
        }
        curr = curr->next;
    }
    return null;

}

wallet accountlist :: returnwallet(string user){

    node* curr = head;
    wallet null;
    while(curr != nullptr){
        if(curr->user.getemail() == user){
            return curr->w;
        }
        curr = curr->next;
    }
    return null;
}
creditCard accountlist :: returncredit(string user){
    node* curr = head;
    creditCard null;
    while(curr != nullptr){
        if(curr->user.getemail() == user){
            return curr->credit;
        }
        curr = curr->next;
    }
    return null;
}
