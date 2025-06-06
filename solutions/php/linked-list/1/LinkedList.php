<?php

declare(strict_types=1);

class LinkedListNode {
    public $value;
    public $next;
    public $prev;

    public function __construct($value, $prev = null, $next = null)
    {
        $this->value = $value;
        $this->prev = $prev;
        $this->next = $next;
    }
}

class LinkedList
{
    private $head;
    private $tail;

    public function __construct()
    {
        $this->head = null;
        $this->tail = null;
    }

    // Adds to tail
    public function push($value){
        $n = new LinkedListNode($value, $this->tail);
        if ($this->tail) $this->tail->next = $n;
        $this->tail = $n;
        if (!$this->head) $this->head = $n;
    }

    // Adds to head
    public function unshift($value){
        $n = new LinkedListNode($value, null, $this->head);
        if ($this->head) $this->head->prev = $n;
        $this->head = $n;
        if (!$this->tail) $this->tail = $n;
    }

    // Removes from tail
    public function pop(){
        if ($this->tail != null){
            $toReturn = $this->tail;
            $this->tail = $toReturn->prev;
            $toReturn->prev = null;
            if ($this->tail) $this->tail->next = null;
            return $toReturn->value;
        }
    }

    // Removes from head
    public function shift(){
        if ($this->head != null){
            $toReturn = $this->head;
            $this->head = $toReturn->next;
            $toReturn->next = null;
            if ($this->head) $this->head->prev = null;
            return $toReturn->value;
        }
    }
}
