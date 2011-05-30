<?php

/**
 * @file
 * VorposMailhandlerParser class.
 */

/**
 * Parses an IMAP stream and creates and email entity.
 */
class VorposMailhandlerParser extends MailhandlerParser {
  public function configForm(&$form_state) {
    $form = array();

    $form['info'] = array(
      '#markup' => '<p>' . t('No settings available') . '</p>',
    );

    return $form;
  }

  /*
   * This defines sources which user's can select to map values to.
   */
  public function getMappingSources() {
    $sources = parent::getMappingSources();
    $sources['subject_question'] = array(
      'name' => t('Question id from subject code'),
      'description' => t('The question id gotten form a code in the subject'),
    );
    return $sources;
  }

  public function sourceForm($source_config) {
    $form = array();
    return $form;
  }

  /**
   * Implementation of FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $fetched = $fetcher_result->getRaw();
    $mailbox = $fetched['mailbox'];
    $result = new FeedsParserResult();
    if (!empty($fetched['messages'])) {
      foreach ($fetched['messages'] as $mid => &$message) {
        $this->commands($message, $source);
        $subject = $message['subject'];
        preg_match('/\[#(?P<question_id>\d+){1,}\]/', $subject, $matches);
        if ($matches['question_id']) {
          $message['subject_question'] = $matches['question_id'];
        }
        $result->items[] = $message;
      }
    }
    return $result;
  }
}
