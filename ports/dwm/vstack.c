// vstack.c

void vstack(Monitor *m) {
    unsigned int i, n;
    Client *c;

    for (n = 0, c = m->clients; c; c = c->next)
        if (ISVISIBLE(c)) n++;

    unsigned int h = m->wh / n;
    unsigned int y = m->wy;

    for (i = 0, c = m->clients; c; c = c->next) {
        if (ISVISIBLE(c)) {
            resize(c, m->wx, y, m->ww, h - 2 * c->bw, False);
            y += h;
        }
    }
}

