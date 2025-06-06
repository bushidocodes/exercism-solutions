<?php

declare(strict_types=1);

const headers = [
    '/^######(.*)/' => 'h6',
    '/^##(.*)/' => 'h2',
    '/^#(.*)/' => 'h1'
];

function parseMarkdown($markdown)
{
    $lines = explode("\n", $markdown);
    $isInList = false;

    foreach ($lines as &$line) {
        $buffer = $line;

        foreach (headers as $regex => $tag){
            if (preg_match($regex, $buffer, $headerMatches)) {
                $line = "<$tag>" . trim($headerMatches[1]) . "</$tag>";
                continue 2;
            }
        }

        $isBold = false;
        $isItalic = false;

        $isListBullet = preg_match('/\*(.*)/', $buffer, $listBulletMatches);

        if ($isListBullet) {
            $buffer = $listBulletMatches[1];
        }

        if (preg_match('/(.*)__(.*)__(.*)/', $buffer, $boldMatches)) {
            $buffer = $boldMatches[1] . '<em>' . $boldMatches[2] . '</em>' . $boldMatches[3];
            $isBold = true;
        }

        if (preg_match('/(.*)_(.*)_(.*)/', $buffer, $italicsMatches)) {
            $buffer = $italicsMatches[1] . '<i>' . $italicsMatches[2] . '</i>' . $italicsMatches[3];
            $isItalic = true;
        }
        
        if ($isListBullet) {
            $line = '';

            if (!$isInList) {
                $isInList = true;
                $line .= '<ul>';
            }

            $line .= "<li>";

            if (!$isItalic && !$isBold) $line .= "<p>";

            $line .= trim($listBulletMatches[1]);
        } 

        if (!$isListBullet && !preg_match('/<h|<ul|<p|<li/', $buffer)) {
            $line = "<p>$line";
        }
       
        if (preg_match('/(.*)__(.*)__(.*)/', $line, $matches)) {
            $line = $matches[1] . '<em>' . $matches[2] . '</em>' . $matches[3];
            $isBold = true;
        }

        if (preg_match('/(.*)_(.*)_(.*)/', $line, $italicsMatches)) {
            $line = $italicsMatches[1] . '<i>' . $italicsMatches[2] . '</i>' . $italicsMatches[3];
            $isItalic = true;
        }

        if (!$isListBullet || (!$isItalic && !$isBold)) $line .= "</p>";

        if ($isListBullet) {
            $line .= "</li>";
        }

        if (!$isListBullet && $isInList) {
            $line = "</ul>" . $line;
            $isInList = false;
            continue;
        }
    }
    $html = join($lines);

    if ($isInList) $html .= '</ul>';
    return $html;
}
