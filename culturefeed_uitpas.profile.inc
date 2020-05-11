<?php

/**
 * @file
 * Profile implementations for Culturefeed uitpas.
 */

/**
 * Implements hook_culturefeed_ui_profile_sections().
 */
function culturefeed_uitpas_culturefeed_ui_profile_sections() {

  if (culturefeed_uitpas_is_passholder()) {

    // Points.
    $user_info = culturefeed_uitpas_get_uitpas_user();
    /* @var CultureFeed_Uitpas_Passholder $passholder */
    $passholder = $user_info->passholder;

    $vars['intro_text'] = 'blablabla';

    return array(
      'classes' => array('uitpas'),
      'content' => theme('culturefeed_uitpas_profile_section', array(
        'links' => 'Beheer je UiTPAS op <a href="https://www.uitpas.be/?utm_source=uitinvlaanderen&utm_medium=website&utm_campaign=profielpagina&utm_content=ga-naar-uitpas">UiTPAS.be</a>',
        'points_label' => t('Points balance'),
        'points_value' => $passholder->points,
      )),
      'title' => variable_get('culturefeed_uitpas_card_name', 'UiTPAS'),
    );

  }
}
