#include "apc.h"
#include<stdio.h>
#include <stdlib.h>
#include <stddef.h>


int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    int carry = 0;

    while (t1 || t2)
    {
        int res1 = (t1) ? t1->data : 0;
        int res2 = (t2) ? t2->data : 0;

        int sum = res1 + res2 + carry;
        int data = sum % 10;
        if (insert_at_first(headR, tailR, data) != SUCCESS) return FAILURE;

        carry = sum / 10;

        if (t1) t1 = t1->prev;
        if (t2) t2 = t2->prev;
    }

    if (carry)
        if (insert_at_first(headR, tailR, carry) != SUCCESS) return FAILURE;

    remove_leading_zeros_list(headR, tailR);
    return SUCCESS;
}

/* subtraction: subtract head2 from head1 (magnitudes). assumes head1 >= head2 */
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    int borrow = 0;

    while (t1)
    {
        int a = t1->data - borrow;
        int b = (t2) ? t2->data : 0;
        if (a < b)
        {
            a += 10;
            borrow = 1;
        }
        else borrow = 0;

        if (insert_at_first(headR, tailR, a - b) != SUCCESS) return FAILURE;

        t1 = t1->prev;
        if (t2) t2 = t2->prev;
    }

    remove_leading_zeros_list(headR, tailR);
    if (*headR == NULL) insert_at_last(headR, tailR, 0);
    return SUCCESS;
}


int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    if (*head1 == NULL || *head2 == NULL)
    {
        insert_at_last(headR, tailR, 0);
        return SUCCESS;
    }

    /* quick zero checks */
    if ((*head1)->data == 0 && (*head1)->next == NULL) { insert_at_last(headR, tailR, 0); return SUCCESS; }
    if ((*head2)->data == 0 && (*head2)->next == NULL) { insert_at_last(headR, tailR, 0); return SUCCESS; }

    int len1 = 0, len2 = 0;
    for (Dlist *p = *head1; p; p = p->next) len1++;
    for (Dlist *p = *head2; p; p = p->next) len2++;

    int size = len1 + len2;
    int *res = calloc(size, sizeof(int));
    if (!res) return FAILURE;

    /* accumulate products: iterate from tails (LSD) */
    int i = 0;
    for (Dlist *a = *tail1; a; a = a->prev, ++i)
    {
        int j = 0;
        for (Dlist *b = *tail2; b; b = b->prev, ++j)
        {
            res[size - 1 - (i + j)] += a->data * b->data;
        }
    }

    /* handle carries from LSD to MSD */
    int carry = 0;
    for (int k = size - 1; k >= 0; --k)
    {
        int tmp = res[k] + carry;
        res[k] = tmp % 10;
        carry = tmp / 10;
    }

    /* skip leading zeros */
    int start = 0;
    while (start < size - 1 && res[start] == 0) start++;

    for (int k = start; k < size; ++k)
    {
        insert_at_last(headR, tailR, res[k]);
    }

    free(res);
    remove_leading_zeros_list(headR, tailR);
    return SUCCESS;
}

/* division: long division producing quotient only (0..9 digits per step) */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **QH, Dlist **QT)
{
    if (*head2 == NULL) return FAILURE;

    /* if dividend < divisor -> 0 */
    int cmp = compare_the_list(head1, tail1, head2, tail2);
    if (cmp == 2)
    {
        insert_at_last(QH, QT, 0);
        return SUCCESS;
    }

    Dlist *tempH = NULL, *tempT = NULL;
    Dlist *p = *head1;

    while (p)
    {
        insert_at_last(&tempH, &tempT, p->data);
        remove_leading_zeros_list(&tempH, &tempT);

        /* find largest digit d in 0..9 s.t. divisor * d <= temp */
        int low = 0, high = 9, best = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            /* compute divisor * mid */
            Dlist *prodH = NULL, *prodT = NULL;
            if (mid == 0)
            {
                insert_at_last(&prodH, &prodT, 0);
            }
            else
            {
                int carry = 0;
                for (Dlist *b = *tail2; b; b = b->prev)
                {
                    int v = b->data * mid + carry;
                    insert_at_first(&prodH, &prodT, v % 10);
                    carry = v / 10;
                }
                while (carry)
                {
                    insert_at_first(&prodH, &prodT, carry % 10);
                    carry /= 10;
                }
                remove_leading_zeros_list(&prodH, &prodT);
            }

            int c = compare_the_list(&prodH, &prodT, &tempH, &tempT);
            delete(&prodH, &prodT);
            if (c == 1) /* prod > temp -> too big */
            {
                high = mid - 1;
            }
            else { /* prod <= temp */
                best = mid;
                low = mid + 1;
            }
        }

        /* subtract divisor * best from temp */
        if (best != 0)
        {
            Dlist *prodH = NULL, *prodT = NULL;
            int carry = 0;
            for (Dlist *b = *tail2; b; b = b->prev)
            {
                int v = b->data * best + carry;
                insert_at_first(&prodH, &prodT, v % 10);
                carry = v / 10;
            }
            while (carry)
            {
                insert_at_first(&prodH, &prodT, carry % 10);
                carry /= 10;
            }
            remove_leading_zeros_list(&prodH, &prodT);

            Dlist *remH = NULL, *remT = NULL;
            subtraction(&tempH, &tempT, &prodH, &prodT, &remH, &remT);

            delete(&tempH, &tempT);
            delete(&prodH, &prodT);

            tempH = remH; tempT = remT;
        }

        insert_at_last(QH, QT, best);
        p = p->next;
    }

    remove_leading_zeros_list(QH, QT);
    delete(&tempH, &tempT);
    return SUCCESS;
}
